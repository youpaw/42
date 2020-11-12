//
// Created by Maxon Gena on 11/8/20.
//

#include "readline.h"

void put_cursor_to_the_end(t_inp *inp)
{
	while (inp->line[inp->curs_y_pos + 1])
		handle_shift_down(inp);
	while (inp->curs_x_pos != inp->line_len[inp->curs_y_pos])
		handle_right_arrow(inp);
}
