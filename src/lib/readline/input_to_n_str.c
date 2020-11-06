//
// Created by Maxon Gena on 8/28/20.
//

#include <cc.h>
#include <stdio.h>
#include "cc_char.h"
#include "readline.h"
#include "cc_str.h"

char *input_to_n_str(t_input input)
{
	char *string;
	char let[5];
	size_t x_edge;
	size_t y_edge;

	x_edge = input.cursor_x_position;
	y_edge = input.cursor_y_position;
	while (input.line[input.cursor_y_position])
		input.cursor_y_position++;
	string = strnew((input.len * 4) + 1 + input.cursor_y_position);
	input.cursor_y_position = 0;
	bzero(let, 5);
	while (input.line[input.cursor_y_position] && input.cursor_y_position <= y_edge)
	{
		input.cursor_x_position = get_prompt_len(input.cursor_y_position);
		while (input.cursor_x_position != input.line_len[input.cursor_y_position] &&
		(input.cursor_x_position != x_edge && input.cursor_y_position <= y_edge))
		{
			vec_get_at(let, input.line[input.cursor_y_position], input.cursor_x_position);
			strcat(string, let);
			input.cursor_x_position++;
		}
		if (input.line[input.cursor_y_position + 1])
			strcat(string, "\n");
		input.cursor_y_position++;
	}
	return string;
}
