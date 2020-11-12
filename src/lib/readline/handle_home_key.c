//
// Created by Maxon Gena on 11/7/20.
//

#include "readline.h"

int			handle_home_key(t_inp *inp)
{
	size_t i;

	i = inp->x_pos - get_prompt_len(inp->y_pos);
	while (i-- != 0)
		handle_left_arrow(inp);
	return (0);
}