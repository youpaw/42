//
// Created by Maxon Gena on 11/8/20.
//

#include "readline.h"
#include "cc_char.h"
#include "cc_str.h"

int			handle_eot(t_inp *inp)
{
	char *tmp;

	if (inp->cursor_y_position || inp->cursor_x_position - get_prompt_len(0))
		handle_eox(inp);
	else
	{
		tmp = inp->hist_storage;
		del_input(inp);
		*inp = input_init(strdup("exit "));
		vec_del(&(inp->line[inp->cursor_y_position]));
		inp->line[inp->cursor_y_position] = NULL;
		inp->cursor_y_position--;
		inp->cursor_x_position = inp->line_len[inp->cursor_y_position];
		inp->hist_storage = tmp;
	}
	return (1);
}
