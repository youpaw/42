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
	if (inp->x_pos - get_prompt_len(inp->y_pos))
	{
		if (!(inp->x_pos % ws.ws_col) && inp->x_pos)
		{
			tputs(tgetstr("up", NULL), 1, &putchar);
			tputs(tgoto(tgetstr("ch", NULL), 1, (inp->x_pos - 1) % ws.ws_col), 1, putchar);
		}
		else
			tputs(tgetstr("le", NULL), 1, &putchar);
		inp->x_pos--;
	}
	else
		putchar('\7');
	return 0;
}