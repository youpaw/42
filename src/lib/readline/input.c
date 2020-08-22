/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 16:54:11 by mgena             #+#    #+#             */
/*   Updated: 2020/08/22 22:17:54 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

t_input input_init(char *line)
{
	t_input inp;

	inp.line = vec_new(8, sizeof(char), NULL);
	if (line)
	{
		inp.len = strlen(line);
		inp.cursor_position = inp.len;
		while (*line)
			vec_push(inp.line, line++);
	}
	else
	{
		inp.cursor_position = 0;
		inp.len = 0;
	}
	return (inp);
}

void	complete_print(t_input *input, t_list **to_print)
{
	char *line;

	line = (*to_print)->content;
	while (*line)
	{
		ft_put(*line);
		vec_push(input->line, line);
		input->len++;
		input->cursor_position++;
		line++;
	}
	lst_del(to_print, NULL);
	*to_print = NULL;
}
