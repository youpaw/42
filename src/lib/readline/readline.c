//
// Created by Darth Butterwell on 8/16/20.
//

#include <sys/ioctl.h>
#include <zconf.h>
#include "readline.h"
#include <stdio.h>
#include "cc_char.h"
#include "cc_graph.h"
#include "cc_str.h"

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
	input->hist_storage = NULL;
	input = NULL;
}

int			readline(char **line)
{
	t_letter key;
	t_input input;

	tty_init();
	input = input_init(*line);
	print_prompt(&input);

	while (42)
	{
		key.num = getch();
		if (handle_key(key.ch, &input))
		{
			*line = input_to_str(input, 1);
			del_input(&input);
			free(g_rd_history_storage);
			g_rd_history_storage = NULL;
			tty_restore();
			return 0;
		}
	}
}

