//
// Created by youpaw on 6/14/20.
//

#include "expand.h"
#include "env.h"

static int handle_dollar(t_expand *expand)
{
	int		direction;
	int 	length;
	t_brace	brace;

	if (!(direction = get_brace(expand->raw[expand->index], &brace)))
	{
		length = get_name_length(expand->raw);
		expand->index += length;
		vec_rm_last(expand->states);
		expand->flags[e_handling_dollar] = 0;
		return (0);
	}

}

int 	expand_input(char **raw)
{
	return (expand_raw(raw, &expand_input_handler, &handle_dollar));
}