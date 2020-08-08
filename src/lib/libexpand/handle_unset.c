//
// Created by Darth Butterwell on 8/8/20.
//

#include "expand.h"

static void	handle_braces(t_expand *expand)
{
	int		direction;
	t_brace	brace;
	t_brace current;

	direction = get_brace(expand->raw[expand->index], &brace);
	if (direction > 0)
	{
		vec_get_last(&current, expand->braces);
		if (current == brace)
			vec_rm_last(expand->braces);
	}
	if (!expand->braces->size)
	{
		expand->flags[e_handling_dollar] = 0;
		vec_rm_last(expand->states);
	}
}
int 	handle_unset(t_expand *expand)
{
	if (expand->flags[e_handling_dollar])
		handle_braces(expand);
	return (0);
}