//
// Created by Maxon Gena on 9/15/20.
//

#include "readline.h"
#include "cc_char.h"
#include <termcap.h>
#include <sys/ioctl.h>
#include <zconf.h>
#include "cc_str.h"

static void	restore_pos(t_inp *inp, int wide)
{
	size_t x_pos;
	size_t y_pos;
	size_t up;

	x_pos = inp->l_len[inp->y_pos] - \
		(inp->x_pos - (inp->x_pos % wide));
	up = x_pos / wide;
	if (!(inp->l_len[inp->y_pos] % wide))
		up--;
	y_pos = inp->y_pos + 1;
	while (inp->line[y_pos])
	{
		up += inp->l_len[y_pos] / wide;
		if (inp->l_len[y_pos] % wide)
			up++;
		y_pos++;
	}
	while (up--)
		tputs(tgetstr("up", NULL), 1, &putchar);
	tputs(tgoto(tgetstr("ch", NULL), 1, inp->x_pos % wide), 1, putchar);
}

void		redraw_input_readline(t_inp *inp)
{
	struct winsize ws;

	if (inp->l_len[inp->y_pos] != inp->x_pos)
	{
		tputs(tgetstr("ce", NULL), 1, &putchar);
		ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
		if (inp->len / ws.ws_col != inp->x_pos / ws.ws_col)
		{
			tputs(tgetstr("do", NULL), 1, &putchar);
			tputs(tgetstr("cr", NULL), 1, &putchar);
			tputs(tgetstr("cd", NULL), 1, &putchar);
			tputs(tgetstr("up", NULL), 1, &putchar);
			tputs(tgoto(tgetstr("ch", NULL), 1, \
				inp->x_pos % ws.ws_col), 1, putchar);
		}
		common_redraw(inp);
		restore_pos(inp, ws.ws_col);
	}
}
