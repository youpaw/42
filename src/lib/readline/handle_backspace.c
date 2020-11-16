/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_backspace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:52:34 by dbutterw          #+#    #+#             */
/*   Updated: 2020/11/12 19:11:12 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "cc_char.h"

int	handle_backspace(t_inp *inp)
{
	if (inp->x_pos - get_prompt_len(inp->y_pos))
	{
		handle_left_arrow(inp);
		handle_del(inp);
		redraw_input_readline(inp);
	}
	else
		putchar('\7');
	return (0);
}
