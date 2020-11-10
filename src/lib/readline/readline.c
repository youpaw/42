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

static void del_input_st(t_input *input)
{
	if (input->hist_storage)
		free(input->hist_storage);
	del_input(input);
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
//		printf("\n%d, %d, %d, %d, %d", key.ch[0], key.ch[1], key.ch[2], key.ch[3], key.num);
		if (handle_key(key.ch, &input))
		{
			*line = input_to_str(input, 1);
			if (input.line)
				del_input_st(&input);
			tty_restore();
			return 0;
		}
	}
}

