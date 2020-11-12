//
// Created by Maxon Gena on 9/8/20.
//

#include "readline.h"
#include "cc_char.h"
#include <termcap.h>
#include <sys/ioctl.h>
#include <zconf.h>

int			handle_shift_down(t_inp *inp)
{
	struct winsize ws;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
	if (inp->line[inp->curs_y_pos + 1] ||
		(inp->line_len[inp->curs_y_pos] / ws.ws_col != inp->curs_x_pos / ws.ws_col))
	{
		tputs(tgetstr("do", NULL), 1, putchar);
		tputs(tgoto(tgetstr("ch", NULL), 1, inp->curs_x_pos % ws.ws_col), 1, putchar);
		if (inp->line_len[inp->curs_y_pos] / ws.ws_col == inp->curs_x_pos / ws.ws_col)
		{
			putchar('\7');
			inp->curs_y_pos++;
			if (inp->line_len[inp->curs_y_pos] > (inp->curs_x_pos % ws.ws_col))
				inp->curs_x_pos %= ws.ws_col;
			else
			{
				inp->curs_x_pos = inp->line_len[inp->curs_y_pos];
				tputs(tgoto(tgetstr("ch", NULL), 1, inp->curs_x_pos % ws.ws_col), 1, putchar);
			}
		}
		else
		{
			inp->curs_x_pos += ws.ws_col;
			if (inp->curs_x_pos > inp->line_len[inp->curs_y_pos])
			{
				inp->curs_x_pos = inp->line_len[inp->curs_y_pos];
				tputs(tgoto(tgetstr("ch", NULL), 1, inp->curs_x_pos % ws.ws_col), 1, putchar);
			}
		}
	}
	else
	{
		putchar('\7');
	}
	return (0);

}
