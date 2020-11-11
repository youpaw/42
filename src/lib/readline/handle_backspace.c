//
// Created by Darth Butterwell on 9/5/20.
//

#include <termcap.h>
#include "readline.h"
#include "cc_mem.h"
#include "cc_char.h"

int handle_backspace(t_inp *inp)
{

	if (inp->cursor_x_position - get_prompt_len(inp->cursor_y_position))
	{
		handle_left_arrow(inp);
		handle_del(inp);
		redraw_input_readline(inp);
	}
	else
		putchar('\7');
	return 0;
}
