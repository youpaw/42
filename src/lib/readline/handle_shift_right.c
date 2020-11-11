//
// Created by Maxon Gena on 10/19/20.
//

#include "readline.h"
#include "cc.h"

int handle_shift_right(t_inp *inp)
{
	t_letter let;

	let.ch[0] = !0;
	while (inp->curs_x_pos != inp->line_len[inp->curs_y_pos])
	{
		vec_get_at(&let, inp->line[inp->curs_y_pos], inp->curs_x_pos);
		if (isspace(let.ch[0]))
			break;
		handle_right_arrow(inp);
	}
	while (inp->curs_x_pos != inp->line_len[inp->curs_y_pos])
	{
		vec_get_at(&let, inp->line[inp->curs_y_pos], inp->curs_x_pos);
		if (!isspace(let.ch[0]))
			break;
		handle_right_arrow(inp);
	}
	return (0);
}
