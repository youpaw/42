//
// Created by Darth Butterwell on 8/7/20.
//
#include "expand.h"
#include "env.h"

static int handle_name_field(t_expand *expand)
{
	int 	length;

	length = get_name_length(expand->raw);
	expand->index += length;
	vec_rm_last(expand->states);
	return (0);
}

int 	handle_dollar(t_expand *expand)
{
	int		direction;
	t_brace	brace;

	if (!(direction = get_brace(expand->raw[expand->index], &brace)))
		return (handle_name_field(expand));
	return (1); //tmp
}
