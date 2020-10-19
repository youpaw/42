//
// Created by Maxon Gena on 8/28/20.
//

#include "cc_char.h"
#include "readline.h"
#include "cc_str.h"

char *input_to_str(t_input input)
{
	char *string;
	char let[5];
	int pos;

	while (input.line[input.cursor_y_position])
		input.cursor_y_position++;
	string = strnew((input.len * 4) + 1 + input.cursor_y_position);
	input.cursor_x_position = input.indent;
	input.cursor_y_position = 0;
	pos = 0;
	while (input.line[input.cursor_y_position])
	{
		while (input.cursor_x_position != input.line_len[input.cursor_y_position])
		{
			vec_get_at(let, input.line[input.cursor_y_position], input.cursor_x_position);
			strcpy(&string[pos], let);
			pos += get_utf8_len(*let);
			input.cursor_x_position++;
		}
		if (input.line[input.cursor_y_position + 1])
		{
			string[pos] = '\n';
			pos++;
		}
		input.cursor_x_position = 0;
		input.cursor_y_position++;
	}
	pos += get_utf8_len(*let);
	string[pos] = 0;
	return string;
}
