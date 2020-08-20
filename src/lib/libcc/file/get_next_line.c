/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:25:30 by dbutterw          #+#    #+#             */
/*   Updated: 2020/01/06 14:39:22 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_file.h"
#include "cc_avl.h"
#include "cc_str.h"
#include "memory/cc_mem.h"
#include <unistd.h>
#include <stdlib.h>

static int			cmp(const int *fd1, const int *fd2, void *param)
{
	(void)param;
	return (*fd1 - *fd2);
}

static void			del(void *str)
{
	free(str);
}

static void			insert_file(t_avl_obj *files, int fd)
{
	t_avl_pair pair;

	pair.key = xmalloc(sizeof(int));
	memmove(pair.key, &fd, sizeof(int));
	pair.value = strnew(0);
	avl_insert(files, &pair);
}

static int		readline(t_avl_pair *file, char **line)
{
	char	buff[BUFF_SIZE + 1];
	char	*rst;
	char	*tmp;
	size_t	size;

	size = 1;
	while (size > 0)
	{
		if ((rst = strchr(file->value, '\n')))
			*rst++ = '\0';
		tmp = strjoin(*line, file->value);
		free(*line);
		*line = tmp;
		if (rst)
		{
			*rst ? strcpy(file->value, rst) : bzero(file->value, 1);
			return (1);
		}
		size = read(*(int*)(file->key), buff, BUFF_SIZE);
		if (!size && **line)
			return (1);
		free(file->value);
		file->value = strsub(buff, 0, size);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_avl_obj 	*files = NULL;
	t_avl_pair 			*file;

	if (fd < 0 || !line || read(fd, NULL, 0) < 0)
		return (-1);
	if (!files)
		files = avl_new(0, (int (*)(const void *, const void *, int)) &cmp, &del);
	if (!(file = avl_get_pair(files, &fd)))
	{
		insert_file(files, fd);
		file = avl_get_pair(files, &fd);
	}
	*line = strnew(0);
	return (readline(file, line));
}
