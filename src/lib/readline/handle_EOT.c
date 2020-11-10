//
// Created by Maxon Gena on 11/8/20.
//

#include "readline.h"
#include "cc_char.h"
#include <unistd.h>

int			handle_EOT(t_input *inp)
{
	if (inp->cursor_y_position || inp->cursor_x_position - get_prompt_len(0))
		handle_EOX(inp);
	else
		exit(0);
	return (1);
}
