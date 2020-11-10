//
// Created by Maxon Gena on 11/8/20.
//

#include "readline.h"

void put_cursor_to_the_end(t_inp *inp)
{
	while (inp->line[inp->cursor_y_position + 1])
		handle_shift_down(inp);
	while (inp->cursor_x_position != inp->line_len[inp->cursor_y_position])
		handle_right_arrow(inp);
}
