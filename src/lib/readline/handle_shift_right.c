//
// Created by Maxon Gena on 10/19/20.
//

#include "readline.h"
#include "cc.h"

int	handle_shift_right(t_inp *inp)
{
	t_let let;

	let.ch[0] = !0;
	while (inp->x_pos != inp->l_len[inp->y_pos])
	{
		vec_get_at(&let, inp->line[inp->y_pos], inp->x_pos);
		if (isspace(let.ch[0]))
			break ;
		handle_right_arrow(inp);
	}
	while (inp->x_pos != inp->l_len[inp->y_pos])
	{
		vec_get_at(&let, inp->line[inp->y_pos], inp->x_pos);
		if (!isspace(let.ch[0]))
			break ;
		handle_right_arrow(inp);
	}
	return (0);
}
