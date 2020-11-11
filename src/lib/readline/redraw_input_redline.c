//
// Created by Maxon Gena on 9/15/20.
//

#include "readline.h"
#include "cc_char.h"
#include <termcap.h>
#include <sys/ioctl.h>
#include <zconf.h>
#include "cc_str.h"

static void restore_pos(t_inp *inp, int wide)
{
	size_t x_pos;
	size_t y_pos;
	size_t up;

	x_pos = inp->line_len[inp->cursor_y_position] - (inp->cursor_x_position - (inp->cursor_x_position % wide));
	up = x_pos / wide;
	if (!(inp->line_len[inp->cursor_y_position] % wide))
		up--;
	y_pos = inp->cursor_y_position + 1;
	while (inp->line[y_pos])
	{
		up += inp->line_len[y_pos] / wide;
		if (inp->line_len[y_pos] % wide)
			up++;
		y_pos++;
	}
	while (up--)
		tputs(tgetstr("up", NULL), 1, &putchar);
	tputs(tgoto(tgetstr("ch", NULL), 1, inp->cursor_x_position % wide), 1, putchar);
}

void redraw_input_readline(t_inp *inp)
{
	struct winsize ws;

	if (inp->line_len[inp->cursor_y_position] != inp->cursor_x_position)
	{
		tputs(tgetstr("ce", NULL), 1, &putchar); //clear till the end of curr line
		ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
		if (inp->len / ws.ws_col != inp->cursor_x_position / ws.ws_col)
		{
			tputs(tgetstr("do", NULL), 1, &putchar); //move cursor vertically down one line
			tputs(tgetstr("cr", NULL), 1, &putchar); //move cursor to the beginning of line
			tputs(tgetstr("cd", NULL), 1, &putchar); //clear line and all bellow the cursor pos
			tputs(tgetstr("up", NULL), 1, &putchar);
			tputs(tgoto(tgetstr("ch", NULL), 1, inp->cursor_x_position % ws.ws_col), 1, putchar);

		}
		common_redraw(inp);
		restore_pos(inp, ws.ws_col);
	}
}