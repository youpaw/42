/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_save.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:52:34 by dbutterw          #+#    #+#             */
/*   Updated: 2020/11/12 19:11:12 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "history.h"
#include "cc.h"

void	hist_save(void)
{
	int		i;
	int		file_fd;
	char	*str;

	if ((file_fd = open(g_hist.file_path, O_WRONLY | O_TRUNC | O_CREAT,
									S_IREAD | S_IWRITE)) == -1)
		return ;
	i = 0;
	if (g_hist.commands->size > HIST_FILE_SIZE)
		i = (int)g_hist.commands->size - HIST_FILE_SIZE;
	while (i < (int)g_hist.commands->size)
	{
		vec_get_at(&str, g_hist.commands, i++);
		fdputendl(str, file_fd);
	}
	vec_del(&g_hist.commands);
	close(file_fd);
}
