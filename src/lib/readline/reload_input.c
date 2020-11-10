//
// Created by Maxon Gena on 11/8/20.
//

#include "readline.h"
#include "cc_str.h"
#include <termcap.h>
#include "cc_char.h"

void del_input(t_input *input)
{
	size_t i;

	i = 0;
	while (input->line[i])
	{
		vec_del(&(input->line[i++]));
	}
	free(input->line_len);
	free(input->line);
	input->line_len = NULL;
	input->line = NULL;
}

void reload_input(t_input *inp, char *str)
{
	char *tmp;

	tmp = inp->hist_storage;
	clear_display_input(inp);
	del_input(inp);
	*inp = input_init(str);
	if (*str)
	{
		free(inp->line[inp->cursor_y_position]);
		inp->line[inp->cursor_y_position] = NULL;
		inp->cursor_y_position--;
		inp->cursor_x_position = inp->line_len[inp->cursor_y_position];
		redraw_input(*inp, str);
	}
	else
	{
		tputs(tgetstr("cr", NULL), 1, putchar);
		tputs(tgetstr("ce", NULL), 1, putchar);
		print_prompt(inp);
	}

	inp->hist_storage = tmp;
}

