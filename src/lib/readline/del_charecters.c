/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_charecters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 12:34:59 by mgena             #+#    #+#             */
/*   Updated: 2020/08/22 17:39:07 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

int backspace_pressed(t_input *input)
{
	if (input->cursor_position)
	{
		left_arrow_pressed(input);
		tputs(tgetstr("dc", NULL), 1, ft_put);
		vec_rm_at(input->line, input->cursor_position);
	}
	return 0;
}

int			del_pressed(t_input *input)
{
	if (input->cursor_position != input->len)
	{
		tputs(tgetstr("dc", NULL), 1, ft_put);
		vec_rm_at(input->line, input->cursor_position);
	}
	return 0;
}
