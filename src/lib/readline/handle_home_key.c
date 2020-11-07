//
// Created by Maxon Gena on 11/7/20.
//

#include "readline.h"

int			handle_home_key(t_input *inp)
{
	size_t i;

	i = inp->cursor_x_position - get_prompt_len(inp->cursor_y_position);
	while (i-- != 0)
		handle_left_arrow(inp);
	return (0);
}