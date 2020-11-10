//
// Created by Maxon Gena on 10/19/20.
//

#include "readline.h"
#include "cc.h"

int handle_shift_right(t_inp *inp)
{
	t_letter let;

	let.ch[0] = !0;
	while (inp->cursor_x_position != inp->line_len[inp->cursor_y_position])
	{
		vec_get_at(&let, inp->line[inp->cursor_y_position], inp->cursor_x_position);
		if (isspace(let.ch[0]))
			break;
		handle_right_arrow(inp);
	}
	while (inp->cursor_x_position != inp->line_len[inp->cursor_y_position])
	{
		vec_get_at(&let, inp->line[inp->cursor_y_position], inp->cursor_x_position);
		if (!isspace(let.ch[0]))
			break;
		handle_right_arrow(inp);
	}
	return (0);
}
