//
// Created by Maxon Gena on 9/8/20.
//

#include "readline.h"
#include "cc_char.h"
#include <termcap.h>
#include <sys/ioctl.h>
#include <zconf.h>

static void	move_on_right_place(t_inp *inp, size_t wide)
{
	if (inp->l_len[inp->y_pos] / wide == \
					inp->x_pos / wide)
	{
		inp->y_pos++;
		if (inp->l_len[inp->y_pos] > (inp->x_pos % wide))
			inp->x_pos %= wide;
		else
		{
			inp->x_pos = inp->l_len[inp->y_pos];
			tputs(tgoto(tgetstr("ch", NULL), 1,\
					inp->x_pos % wide), 1, putchar);
		}
	}
	else
	{
		inp->x_pos += wide;
		if (inp->x_pos > inp->l_len[inp->y_pos])
		{
			inp->x_pos = inp->l_len[inp->y_pos];
			tputs(tgoto(tgetstr("ch", NULL), 1,\
					inp->x_pos % wide), 1, putchar);
		}
	}
}

int			handle_shift_down(t_inp *inp)
{
	struct winsize ws;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
	if (inp->line[inp->y_pos + 1] ||
		(inp->l_len[inp->y_pos] / ws.ws_col != \
					inp->x_pos / ws.ws_col))
	{
		tputs(tgetstr("do", NULL), 1, putchar);
		tputs(tgoto(tgetstr("ch", NULL), 1, \
			inp->x_pos % ws.ws_col), 1, putchar);
		move_on_right_place(inp, ws.ws_col);
	}
	else
		putchar('\7');
	return (0);
}
