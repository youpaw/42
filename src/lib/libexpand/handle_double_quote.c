//
// Created by Darth Butterwell on 8/7/20.
//

#include "expand.h"

int 	handle_double_quote(t_expand *expand)
{
	t_state state;
	char c;

	state = e_unset;
	c = expand->raw[expand->index];
	if (c == '!')
		state = e_bang;
	else if (c == '$')
		state = e_dollar;
	else if (c == '\\')
		state = e_back_slash;
	else if (c == '\"')
		vec_rm_last(expand->states);
	if (state != e_unset)
		vec_push(expand->states, &state);
	return (0);
}