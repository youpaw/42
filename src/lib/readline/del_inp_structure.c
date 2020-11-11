//
// Created by Maxon Gena on 11/11/20.
//

#include "readline.h"

void	del_input(t_inp *input)
{
	size_t i;

	i = 0;
	while (input->line[i])
		vec_del(&(input->line[i++]));
	vec_del(&(input->line[i]));
	free(input->line_len);
	free(input->line);
	input->line_len = NULL;
	input->line = NULL;
}
