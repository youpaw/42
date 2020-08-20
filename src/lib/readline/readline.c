//
// Created by Darth Butterwell on 8/16/20.
//

#include "readline.h"
#include <string.h>
#include <stdio.h>


int		get_key_func(char key[4], t_input *input)
{
	if (!strcmp(key, "\33"))
		return (0); //TODO escape character
	else if (!strcmp(key, "\33\133\101") || !(strcmp(key, "\20")))
		return (0); //TODO arrow up
	else if (!strcmp(key, "\33\133\102") || !(strcmp(key, "\16")))
		return (0); //TODO arrow down
	else if (!strcmp(key, "\33\133\103") || !(strcmp(key, "\6")))
		return right_arrow_pressed(input);
	else if (!strcmp(key, "\33\133\104") || !(strcmp(key, "\2")))
		return left_arrow_pressed(input);
	else if (!strcmp(key, "\177"))
		return backspace_pressed(input);
	else if (key[0] == 27 && key[1] == 91 && key[2] == 51 && key[3] == 126)
		return del_pressed(input);
	else if (!strcmp(key, "\t"))
		return autocomplete(input);
	else if (!strcmp(key, "\n"))
		return (1); //enter return nozero value
	// TODO think about error values
	else
	{
		symbol_key_pressed(input, key[0]);
		return (0);
	}
}
int		readline(char **line)
{
	char key[4];
	t_input input;

	input = input_init();
	while (42)
	{
		bzero(key, 4);
		read(STDIN_FILENO, key, 4);
		if (get_key_func(key, &input))
		{
//			printf("\n!!!!!!!!!!!!!!!\n%s\n!!!!!!!!!!!!!!!!\ncurs_pos: %d, len: %d",
//				   (char*)input.line->data, input.cursor_position, input.len);
//			ft_put('\n');
//			ft_putstr((char*)input.line->data);
			return 0;
		}
	}
}

