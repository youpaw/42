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

int left_arrow_pressed(t_input *input)
{
	if (input->cursor_position)
	{
		tputs(tgetstr("le", NULL), 1, ft_put);
		input->cursor_position--;
	}
	else
		ft_putstr("\7");
	return 0;
}

int right_arrow_pressed(t_input *input)
{
	if (input->cursor_position != input->len)
	{
		tputs(tgetstr("nd", NULL), 1, ft_put);
		input->cursor_position++;
	}
	else
		ft_putstr("\7");
	return 0;
}

