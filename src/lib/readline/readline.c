//
// Created by Darth Butterwell on 8/16/20.
//

#include "readline.h"
#include <string.h>
#include <stdio.h>


int		get_key_func(char key[4], t_input *input)
{
//	write(STDOUT_FILENO, key, 4);
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
		return (1); //enter return nozero valu
	// TODO think about error values
	else
	{
		symbol_key_pressed(input, key);
		return (0);
	}
}
int		readline(char **line)
{
	t_letter key;
	t_input input;
	int i = 0;
	char *line;

	input = input_init(*line);
	while (42)
	{
		key.num = getch();
//		printf("\n%d, %d, %d, %d, %d", key.ch[0], key.ch[1], key.ch[2], key.ch[3], key.num);
		if (get_key_func(key.ch, &input))
		{
//			printf("\n!!!!!!!!!!!!!!!\n%s\n!!!!!!!!!!!!!!!!\ncurs_pos: %d, len: %d",
//				   (char*)input.line->data, input.cursor_position, input.len);
			line = vect_to_str(input.line, input.len);
			return 0;
		}
	}
}

