/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_shift_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:54:42 by fmallist          #+#    #+#             */
/*   Updated: 2020/11/10 15:59:49 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <termcap.h>
#include <sys/ioctl.h>
#include <zconf.h>
#include <stdio.h>

static void	move_on_right_place(t_inp *inp, int wide)
{
	if (inp->x_pos < (size_t)wide || inp->x_pos == 0)
	{
		inp->y_pos--;
		if (inp->x_pos % wide > inp->l_len[inp->y_pos] % wide)
		{
			inp->x_pos = inp->l_len[inp->y_pos];
			tputs(tgoto(tgetstr("ch", NULL), 1,\
					inp->x_pos % wide), 1, putchar);
		}
		else
			inp->x_pos = inp->x_pos % wide + \
				((inp->l_len[inp->y_pos] / wide) * wide);
	}
	else
		inp->x_pos -= wide;
}

int			handle_shift_up(t_inp *inp)
{
	struct winsize ws;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
	if (inp->y_pos || (inp->x_pos != 0 && inp->x_pos >= ws.ws_col))
	{
		tputs(tgetstr("up", NULL), 1, putchar);
		move_on_right_place(inp, ws.ws_col);
		if (inp->x_pos < (size_t)get_prompt_len(inp->y_pos))
		{
			tputs(tgoto(tgetstr("ch", NULL), 1,\
				get_prompt_len(inp->y_pos)), 1, putchar);
			inp->x_pos = get_prompt_len(inp->y_pos);
		}
	}
	else
		putchar('\7');
	return (0);
}
