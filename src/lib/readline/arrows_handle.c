/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 12:01:01 by mgena             #+#    #+#             */
/*   Updated: 2020/08/22 17:39:07 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <stdio.h>

int left_arrow_pressed(t_input *input)
{
	unsigned char ch[5];
	int len;
	if (input->cursor_position)
	{
		g_input_changed_flg = 1;
		bzero(ch, 5);
		vec_get_at(ch, input->line, input->cursor_position - 1);
		len = get_displayed_symbol_len(ch);
		while (len-- != 0)
		{
			tputs(tgetstr("le", NULL), 1, putchar);
		}
		input->cursor_position--;
	}
	else
		ft_putstr("\7");
	return 0;
}

int right_arrow_pressed(t_input *input)
{
	unsigned char ch[5];
	int len;

	if (input->cursor_position != input->len)
	{
		g_input_changed_flg = 1;
		bzero(ch, 5);
		vec_get_at(ch, input->line, input->cursor_position);
		len = get_displayed_symbol_len(ch);
		while (len-- != 0)
			tputs(tgetstr("nd", NULL), len, ft_put);
		input->cursor_position++;
	}
	else
		ft_putstr("\7");
	return 0;
}

