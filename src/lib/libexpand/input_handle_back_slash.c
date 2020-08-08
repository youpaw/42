//
// Created by Darth Butterwell on 8/7/20.
//

#include "expand.h"
#include "string/cc_str.h"

int 	input_handle_back_slash(t_expand *expand)
{
	char c;

	c = expand->raw[expand->index];
	if (c == '\n')
	{
		if (expand->index == expand->size - 1)
			return (E_INCOMPLETE_INPUT);
		strcpy(expand->raw + expand->index - 1, \
		expand->raw + expand->index + 1);
		expand->size -= 2;
		expand->index -= 2;
	}
	vec_rm_last(expand->states);
	return (0);
}