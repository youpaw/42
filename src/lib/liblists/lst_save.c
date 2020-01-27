/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 21:20:54 by darugula          #+#    #+#             */
/*   Updated: 2019/09/16 21:20:56 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

static int	g_fd = -1;
static char *g_separator = NULL;

void	 save_item(t_list *elem)
{
	const char *str;

	str = (const char *)elem->content;
	write(g_fd, str, strlen(str));
	write(g_fd, g_separator, strlen(g_separator));
}

int		lst_save(t_list *head, int fd, const char *separator)
{
	if (g_fd != -1)
	{
		//debug_printf 
		return (E_FAIL);
	}
	g_fd = fd;
	g_separator = (char *)separator;
	lstiter(head, save_item);
	g_fd = -1;
	g_separator = NULL;
}