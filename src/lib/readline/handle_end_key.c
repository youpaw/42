//
// Created by Maxon Gena on 11/7/20.
//

#include "readline.h"

int			handle_end_key(t_input *inp)
{
	while (inp->cursor_x_position != inp->line_len[inp->cursor_y_position])
		handle_right_arrow(inp);
	return (0);
}
