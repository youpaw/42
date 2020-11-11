//
// Created by Maxon Gena on 10/19/20.
//

#include "readline.h"
#include "cc.h"

int handle_shift_left(t_inp *inp)
{
	t_letter let;

	let.ch[0] = !0;
	while (inp->curs_x_pos - FIRST_PROMPT_LEN)
	{
		vec_get_at(&let, inp->line[inp->curs_y_pos], inp->curs_x_pos);
		if (isspace(let.ch[0]))
			break;
		handle_left_arrow(inp);
	}
	while (inp->curs_x_pos != inp->line_len[inp->curs_y_pos])
	{
		vec_get_at(&let, inp->line[inp->curs_y_pos], inp->curs_x_pos);
		if (!isspace(let.ch[0]))
			break;
		handle_left_arrow(inp);
	}
	return (0);
}
