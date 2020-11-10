//
// Created by Darth Butterwell on 8/16/20.
//

#include "readline.h"
#include "cc_char.h"
#include "cc_graph.h"

static void	del_input_st(t_inp *input)
{
	if (input->hist_storage)
		free(input->hist_storage);
	del_input(input);
}

int			readline(char **line)
{
	t_letter	key;
	t_inp		input;

	tty_init();
	input = input_init(*line);
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
