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
#include <termcap.h>
#include <sys/ioctl.h>
#include <zconf.h>
#include "cc_mem.h"
#include <stdio.h>

int handle_right_arrow(t_input *inp)
{
	struct winsize ws;

	if (inp->cursor_x_position != inp->line_len[inp->cursor_y_position])
	{
		g_input_state_flag = INP_CH_FLAG;
		ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
		if (!((inp->cursor_x_position + 1) % ws.ws_col) && inp->cursor_x_position)
		{
			tputs(tgetstr("do", NULL), 1, &putchar);
			tputs(tgetstr("cr", NULL), 1, &putchar);
			putchar('\7');
		}
		else
			tputs(tgetstr("nd", NULL), 1, &putchar);
		inp->cursor_x_position++;
	}
	else
	{
		putchar('\7');
	}
	return 0;
}

