//
// Created by Maxon Gena on 9/15/20.
//

#include "readline.h"
#include "cc_char.h"
#include <termcap.h>
#include <sys/ioctl.h>
#include <zconf.h>

void redraw_input_adding(t_input *inp)
{
	struct winsize ws;

	if (inp->line_len[inp->cursor_y_position] != inp->cursor_x_position)
	{
		tputs(tgetstr("sc", NULL), 1, &putchar);
		tputs(tgetstr("ei", NULL), 1, &putchar);
		common_redraw(inp);
		tputs(tgetstr("rc", NULL), 1, &putchar);
		tputs(tgetstr("im", NULL), 1, &putchar);
		ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
		if (!((inp->line_len[inp->cursor_y_position] - 1) % (ws).ws_col))
			tputs(tgetstr("up", NULL), 1, &putchar);
		if (!((inp->cursor_x_position) % (ws).ws_col) && inp->cursor_x_position)
		{
			tputs(tgetstr("do", NULL), 1, &putchar);
			tputs(tgetstr("cr", NULL), 1, &putchar);
			putchar('\7');
		}
	}
}
