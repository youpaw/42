//
// Created by Maxon Gena on 11/8/20.
//

#include "readline.h"

void	put_cursor_to_the_end(t_inp *inp)
{
	while (inp->line[inp->y_pos + 1])
		handle_shift_down(inp);
	while (inp->x_pos != inp->l_len[inp->y_pos])
		handle_right_arrow(inp);
}
