//
// Created by Darth Butterwell on 9/5/20.
//

#include "readline.h"
#include "cc_mem.h"
#include "cc_char.h"
#include <sys/ioctl.h>
#include <termcap.h>
#include <zconf.h>

int handle_left_arrow(t_inp *inp)
{
	struct winsize ws;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
	if (inp->cursor_x_position - get_prompt_len(inp->cursor_y_position))
	{
		if (!(inp->cursor_x_position % ws.ws_col) && inp->cursor_x_position)
		{
			tputs(tgetstr("up", NULL), 1, &putchar);
			tputs(tgoto(tgetstr("ch", NULL), 1, (inp->cursor_x_position - 1) % ws.ws_col), 1, putchar);
		}
		else
			tputs(tgetstr("le", NULL), 1, &putchar);
		inp->cursor_x_position--;
	}
	else
		putchar('\7');
	return 0;
}