/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_file.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 13:00:51 by darugula          #+#    #+#             */
/*   Updated: 2020/01/01 13:00:52 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc.h"
#include "h_dlist.h"
#include "history.h"
#include <fcntl.h>
#include <sys/stat.h>

static int	g_fd = -1;
static const char g_separator[] = "\n----------------------\n";
static t_list *g_last = NULL;

int		create_or_open(const char *path)
{
	return (open(path, O_CREAT | O_APPEND | O_RDWR | O_FSYNC, S_IRUSR | S_IWUSR ));
}

int		h_init(const char *path)
{
	int	r;

	if (path == NULL)
	{
		return (2);
	}
	if (g_fd != -1)
	{
		return (3);
	}
	g_fd = create_or_open(path);
	if (g_fd < 0)
	{
		//debug_printf
		//perror("create file failed\n");
		return (E_FAIL);
	}
	r = lst_load(g_fd, g_separator, h_append);
	if (r != E_OK)
	{
		return (r);
	}
	g_last = h_get_last();
	return (E_OK);
}

int		h_close()
{
	if (g_fd != -1)
	{
		close(g_fd);
		g_fd = -1;
	}
	return (h_free());
}

int h_save_new()
{
	int	r;
	t_list *node_to_save;

	if (g_fd == -1)
	{
		return (E_FAIL);
	}
	node_to_save = (g_last == NULL) ? h_get_head() : g_last->next;
	g_last = h_get_last();
	return (node_to_save == NULL ? E_OK : lst_save(node_to_save, g_fd, g_separator));
}