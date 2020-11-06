//
// Created by Maxon Gena on 11/3/20.
//

#include "readline.h"
#include "cc_char.h"

void clear_last_disp_token(char *token, t_input *input)
{
	size_t i;

	i = 0;
	while (token[i])
	{
		handle_backspace(input);
		i += utf8_sizeof_symbol(token[i]);
	}
}