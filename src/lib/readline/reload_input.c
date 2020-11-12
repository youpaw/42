//
// Created by Maxon Gena on 11/8/20.
//

#include "readline.h"
#include "cc_str.h"
#include "cc_char.h"
#include <termcap.h>

void	reload_input(t_inp *inp, char *str)
{
	char *tmp;

	tmp = inp->hist_storage;
	clear_display_input(inp);
	del_input(inp);
	*inp = input_init(strdup(str));
	if (*str)
	{
		vec_del(&(inp->line[inp->y_pos]));
		inp->line[inp->y_pos] = NULL;
		inp->y_pos--;
		inp->x_pos = inp->l_len[inp->y_pos];
		redraw_input(*inp, str);
	}
	else
	{
		tputs(tgetstr("cr", NULL), 1, putchar);
		tputs(tgetstr("ce", NULL), 1, putchar);
		print_prompt(inp);
	}
	inp->hist_storage = tmp;
	free(str);
}
