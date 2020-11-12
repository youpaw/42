//
// Created by Maxon Gena on 8/28/20.
//

#include <cc.h>
#include <stdio.h>
#include "cc_char.h"
#include "readline.h"
#include "cc_str.h"

static void	cat_letter(t_inp *inp, char *string)
{
	char	let[5];

	bzero(let, 5);
	vec_get_at(let, inp->line[inp->y_pos], inp->x_pos);
	strcat(string, let);
	inp->x_pos++;
}

char		*input_to_n_str(t_inp input)
{
	char	*string;
	size_t	x_edge;
	size_t	y_edge;

	x_edge = input.x_pos;
	y_edge = input.y_pos;
	while (input.line[input.y_pos])
		input.y_pos++;
	string = strnew((input.len * 4) + 1 + input.y_pos);
	input.y_pos = 0;
	while (input.line[input.y_pos] && input.y_pos <= y_edge)
	{
		input.x_pos = get_prompt_len(input.y_pos);
		while (input.x_pos != input.l_len[input.y_pos] && \
			(input.x_pos != x_edge && input.y_pos <= y_edge))
			cat_letter(&input, string);
		if (input.line[input.y_pos + 1])
			strcat(string, "\n");
		input.y_pos++;
	}
	return (string);
}
