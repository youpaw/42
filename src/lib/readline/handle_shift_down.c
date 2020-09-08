//
// Created by Maxon Gena on 9/8/20.
//

#include "readline.h"
#include "cc_char.h"
#include <termcap.h>
#include <sys/ioctl.h>
#include <zconf.h>

int			handle_shift_down(t_input *inp)
{
	int height;
	struct winsize ws;

	height = 0;
	if (inp->line[inp->cursor_y_position + 1])
	{
		ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
		height = ((inp->line_len[inp->cursor_y_position] - inp->cursor_x_position) / ws.ws_col) + 1;
		while (height--)
			tputs(tgetstr("do", NULL), 1, putchar);
		inp->cursor_y_position++;
		if (inp->cursor_x_position > inp->line_len[inp->cursor_y_position])
		{
			inp->cursor_x_position = inp->line_len[inp->cursor_y_position];
			tputs(tgoto(tgetstr("ch", NULL), 1, inp->cursor_x_position), 1, putchar);
		}
		else
			inp->cursor_x_position = inp->cursor_x_position % ws.ws_col +\
		((inp->line_len[inp->cursor_y_position] / ws.ws_col) * ws.ws_col);
	}
	else
	{
		putchar('\7');
	}
	return (0);

}
