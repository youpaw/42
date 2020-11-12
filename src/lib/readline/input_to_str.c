//
// Created by Maxon Gena on 8/28/20.
//

#include <cc.h>
#include "readline.h"
#include "cc_str.h"

char	*input_to_str(t_inp input, int newline)
{
	char *string;
	char let[5];

	if (!input.line)
		return (strdup(""));
	while (input.line[input.curs_y_pos])
		input.curs_y_pos++;
	string = xmalloc((sizeof(char) * input.len * 4) + 1 + input.curs_y_pos);
	*string = '\0';
	input.curs_y_pos = 0;
	bzero(let, 5);
	while (input.line[input.curs_y_pos])
	{
		input.curs_x_pos = get_prompt_len(input.curs_y_pos);
		while (input.curs_x_pos != input.line_len[input.curs_y_pos])
		{
			vec_get_at(let, input.line[input.curs_y_pos], input.curs_x_pos);
			strcat(string, let);
			input.curs_x_pos++;
		}
		if (input.line[input.curs_y_pos + 1] && newline)
			strcat(string, "\n");
		input.curs_y_pos++;
	}
	return (string);
}
