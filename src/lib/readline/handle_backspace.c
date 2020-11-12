//
// Created by Darth Butterwell on 9/5/20.
//

#include <termcap.h>
#include "readline.h"
#include "cc_mem.h"
#include "cc_char.h"

int handle_backspace(t_inp *inp)
{

	if (inp->curs_x_pos - get_prompt_len(inp->curs_y_pos))
	{
		handle_left_arrow(inp);
		handle_del(inp);
		redraw_input_readline(inp);
	}
	else
		putchar('\7');
	return 0;
}
