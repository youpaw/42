//
// Created by Maxon Gena on 9/15/20.
//

#include "readline.h"
#include "cc_char.h"
#include <termcap.h>
#include <sys/ioctl.h>
#include <zconf.h>

void redraw_input_del(t_input *inp)
{
	struct winsize ws;

	if (inp->line_len[inp->cursor_y_position] != inp->cursor_x_position)
	{
		tputs(tgetstr("sc", NULL), 1, &putchar);
		tputs(tgetstr("ce", NULL), 1, &putchar); //clear till the end of curr line
		ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
		if (inp->len / ws.ws_col != inp->cursor_x_position / ws.ws_col)
		{
			tputs(tgetstr("do", NULL), 1, &putchar); //move cursor vertically down one line
			tputs(tgetstr("cr", NULL), 1, &putchar); //move cursor to the beginning of line
			tputs(tgetstr("cd", NULL), 1, &putchar); //clear line and all bellow the cursor pos
		}
		tputs(tgetstr("rc", NULL), 1, &putchar);
		tputs(tgetstr("ei", NULL), 1, &putchar);
		common_redraw(inp);
		tputs(tgetstr("rc", NULL), 1, &putchar);
		tputs(tgetstr("im", NULL), 1, &putchar);
	}
}