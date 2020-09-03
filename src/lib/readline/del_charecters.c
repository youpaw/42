/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_charecters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 12:34:59 by mgena             #+#    #+#             */
/*   Updated: 2020/08/26 15:42:11 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

int backspace_pressed(t_input *input)
{
	unsigned char ch[5];
	int len;
	if (input->cursor_x_position)
	{
		g_input_changed_flg = 1;
		bzero(ch, 5);
		vec_get_at(ch, input->line, input->cursor_x_position - 1);
		len = get_displayed_symbol_len(ch);
		left_arrow_pressed(input);
		while (len-- != 0)
			tputs(tgetstr("dc", NULL), 1, ft_put);
		vec_rm_at(input->line, input->cursor_x_position);
		input->len--;
	}
	else
		ft_put('\7');
	return 0;
}

int			del_pressed(t_input *input)
{
	unsigned char ch[5];
	int len;

	if (input->cursor_x_position != input->len)
	{
		bzero(ch, 5);
		vec_get_at(ch, input->line, input->cursor_x_position);
		len = get_displayed_symbol_len(ch);
		while (len-- != 0)
			tputs(tgetstr("dc", NULL), 1, ft_put);
		vec_rm_at(input->line, input->cursor_x_position);
		input->len--;
	}
	else
		ft_put('\7');
	return 0;
}