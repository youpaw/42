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


int			readline(char **line)
{
	t_letter key;
	t_input input;
	t_graph graph;
	char 	**strs;

	tty_init();
	input = input_init(*line);
	print_prompt(&input);
//	fill_complition_graph(&graph);
//	strs = graph_get_names(&graph, "ab");
//	strarr_print(strs, NULL, "\n");
	while (42)
	{
		key.num = getch();
//		printf("\n%d, %d, %d, %d, %d", key.ch[0], key.ch[1], key.ch[2], key.ch[3], key.num);
		if (handle_key(key.ch, &input))
		{
			*line = input_to_str(input);
//			printf("|%s|", input.line_len[input.cursor_y_position], *line);
//			graph_del(&graph);
			tty_restore();
			return 0;
		}
	}
}

