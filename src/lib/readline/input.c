/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 16:54:11 by mgena             #+#    #+#             */
/*   Updated: 2020/08/28 14:23:31 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <stdio.h>

t_input input_init(char *line)
{
	t_input inp;

	inp.line = vec_new(8, sizeof(char[4]), NULL);
	if (line)
	{
		inp.len = strlen(line);
		inp.cursor_x_position = inp.len;
		while (*line)
			vec_push(inp.line, line++);
	}
	else
	{
		inp.cursor_x_position = 0;
		inp.len = 0;
	}
	return (inp);
}

void	complete_print(t_input *input, t_list **to_print)
{
	char *line;

	g_input_changed_flg = 1;
	line = (*to_print)->content;
	while (*line)
	{
		ft_put(*line);
		vec_push(input->line, line);
		input->len++;
		input->cursor_x_position++;
		line++;
	}
	lst_del_circle(to_print, NULL);
	*to_print = NULL;
}

int			get_unicod_len(char ch)
{
	if (ch >= 0)
		return (1);
	else if (ch & -16)
		return(4);
	else if (ch & -32)
		return(3);
	else if (ch & -64)
		return(2);
	return 0;
}

int 	getch(void)
{
	static char	buf[BUFFSIZE];
	t_letter	res;
	int 		len;

	bzero(res.ch, 5);
	if (buf[0] == '\0')
		read(STDIN_FILENO, buf, BUFFSIZE);
	if (buf[0] == '\33' && buf[1] == '\133')
	{
		strncpy(res.ch, buf, 4);
		bzero(buf, BUFFSIZE);
	}
	else
	{
		len = get_unicod_len(buf[0]);
		strncpy(res.ch, buf, len);
		memmove(buf, &buf[len], BUFFSIZE - len);
		bzero(&buf[BUFFSIZE - len], len);
	}
	return (res.num);
}
