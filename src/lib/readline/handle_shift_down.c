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
	if (inp->line[inp->cursor_y_position + 1] ||
	(inp->line_len[inp->cursor_y_position] / ws.ws_col != inp->cursor_x_position / ws.ws_col))
	{
		tputs(tgetstr("do", NULL), 1, putchar);
		tputs(tgoto(tgetstr("ch", NULL), 1, inp->cursor_x_position % ws.ws_col), 1, putchar);
		if (inp->line_len[inp->cursor_y_position] / ws.ws_col == inp->cursor_x_position / ws.ws_col)
		{
			putchar('\7');
			inp->cursor_y_position++;
			if (inp->line_len[inp->cursor_y_position] > (inp->cursor_x_position % ws.ws_col))
				inp->cursor_x_position %= ws.ws_col;
			else
			{
				inp->cursor_x_position = inp->line_len[inp->cursor_y_position];
				tputs(tgoto(tgetstr("ch", NULL), 1, inp->cursor_x_position % ws.ws_col), 1, putchar);
			}
		}
		else
		{
			inp->cursor_x_position += ws.ws_col;
			if (inp->cursor_x_position > inp->line_len[inp->cursor_y_position])
			{
				inp->cursor_x_position = inp->line_len[inp->cursor_y_position];
				tputs(tgoto(tgetstr("ch", NULL), 1, inp->cursor_x_position % ws.ws_col), 1, putchar);
			}
		}
	}
	else
	{
		putchar('\7');
	}
	return (0);

}
