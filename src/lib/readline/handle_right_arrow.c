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
#include "cc_char.h"
#include "cc_mem.h"

int handle_right_arrow(t_input *inp)
{
	unsigned char ch[5];
	int len;
	struct winsize ws;

	if (inp->cursor_x_position != inp->line_len[inp->cursor_y_position])
	{
		g_input_changed_flg = 1;
		bzero(ch, 5);
		ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
		if (inp->cursor_x_position % (ws.ws_col - 1) == 0)
		{
			tputs(tgetstr("do", NULL), 1, &putchar);
			tputs(tgetstr("cr", NULL), 1, &putchar);
			putchar('\7');
		}
		else
		{
			vec_get_at(ch, inp->line[inp->cursor_y_position], inp->cursor_x_position);
			len = get_displayed_symbol_len(ch);
			while (len-- != 0)
				tputs(tgetstr("nd", NULL), len, &putchar);
		}
		inp->cursor_x_position++;
	}
	else
	{
		putchar('\7');
	}
	return 0;
}

