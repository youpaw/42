//
// Created by Maxon Gena on 8/28/20.
//

#include <cc.h>
#include <stdio.h>
#include "cc_char.h"
#include "readline.h"
#include "cc_str.h"

char *input_to_n_str(t_inp input)
{
	char *string;
	char let[5];
	size_t x_edge;
	size_t y_edge;

	x_edge = input.curs_x_pos;
	y_edge = input.curs_y_pos;
	while (input.line[input.curs_y_pos])
		input.curs_y_pos++;
	string = strnew((input.len * 4) + 1 + input.curs_y_pos);
	input.curs_y_pos = 0;
	bzero(let, 5);
	while (input.line[input.curs_y_pos] && input.curs_y_pos <= y_edge)
	{
		input.curs_x_pos = get_prompt_len(input.curs_y_pos);
		while (input.curs_x_pos != input.line_len[input.curs_y_pos] &&
			   (input.curs_x_pos != x_edge && input.curs_y_pos <= y_edge))
		{
			vec_get_at(let, input.line[input.curs_y_pos], input.curs_x_pos);
			strcat(string, let);
			input.curs_x_pos++;
		}
		if (input.line[input.curs_y_pos + 1])
			strcat(string, "\n");
		input.curs_y_pos++;
	}
	return string;
}
