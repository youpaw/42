//
// Created by Maxon Gena on 11/8/20.
//

#include "readline.h"
#include "cc_char.h"
#include "cc_str.h"

int			handle_eot(t_inp *inp)
{
	char *tmp;

	if (inp->curs_y_pos || inp->curs_x_pos - get_prompt_len(0))
		handle_eox(inp);
	else
	{
		tmp = inp->hist_storage;
		del_input(inp);
		*inp = input_init(strdup("exit "));
		vec_del(&(inp->line[inp->curs_y_pos]));
		inp->line[inp->curs_y_pos] = NULL;
		inp->curs_y_pos--;
		inp->curs_x_pos = inp->line_len[inp->curs_y_pos];
		inp->hist_storage = tmp;
	}
	return (1);
}
