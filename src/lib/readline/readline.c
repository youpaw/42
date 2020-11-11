//
// Created by Darth Butterwell on 8/16/20.
//

#include <zconf.h>
#include "readline.h"
#include "cc_char.h"
#include "cc_graph.h"
#include "cc_str.h"
#include "cc_num.h"

static void	del_input_st(t_inp *input)
{
	if (input->hist_storage)
		free(input->hist_storage);
	del_input(input);
}

static int	check_eox(t_inp *inp)
{
	char ch[5];

	if (inp->curs_y_pos)
	{
		vec_get_at(ch, inp->line[inp->curs_y_pos - 1], inp->line_len[inp->curs_y_pos - 1] - 1);
		if (*ch == '\4')
		{
			vec_del(&inp->line[inp->curs_y_pos]);
			inp->line[inp->curs_y_pos] = NULL;
			inp->curs_x_pos = inp->line_len[--inp->curs_y_pos];
			puts("!");
			handle_backspace(inp);
			return (1);
		}
	}
	return (0);



}

int			readline(char **line)
{
	t_letter	key;
	t_inp		input;

	tty_init();
	input = input_init(*line);
	if (!check_eox(&input))
		print_prompt(&input);
	while (42)
	{
		key.num = getch();
		if (handle_key(key.ch, &input))
		{
			*line = input_to_str(input, 1);
			if (input.line)
				del_input_st(&input);
			tty_restore();
			return (0);
		}
	}
}
