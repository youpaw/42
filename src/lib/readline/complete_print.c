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

void	complete_print(t_input *input, t_list **to_print)
{
	char *line;

	g_input_changed_flg = 1;
	line = (*to_print)->content;
	while (*line)
	{
		putchar(*line);
		vec_push(input->line, line);
		input->len++;
		input->cursor_x_position++;
		line++;
	}
	lst_del_circle(to_print, NULL);
	*to_print = NULL;
}
