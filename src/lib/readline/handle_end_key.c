//
// Created by Maxon Gena on 11/7/20.
//

#include "readline.h"

int			handle_end_key(t_inp *inp)
{
	while (inp->curs_x_pos != inp->line_len[inp->curs_y_pos])
		handle_right_arrow(inp);
	return (0);
}
