//
// Created by Darth Butterwell on 9/5/20.
//

#include "readline.h"
#include "cc_str.h"

t_input input_init(char *line)
{
	t_input inp;

	inp.line = vec_new(8, sizeof(char[4]), NULL);
	if (line)
	{
		inp.len = strlen(line);
		inp.cursor_x_position = inp.len;
		while (*line)
			vec_push(inp.line, line++);
	}
	else
	{
		inp.cursor_x_position = 0;
		inp.len = 0;
	}
	return (inp);
}