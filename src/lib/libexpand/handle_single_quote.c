//
// Created by Darth Butterwell on 8/7/20.
//
#include "expand.h"

int 	handle_single_quote(t_expand *expand)
{
	while (expand->raw[expand->index] != '\'' && expand->index < expand->size)
		expand->index++;
	if (expand->index == expand->size)
		return (E_INCOMPLETE_INPUT);
	vec_rm_last(expand->states);
	return (0);
}