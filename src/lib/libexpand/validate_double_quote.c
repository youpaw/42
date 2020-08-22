//
// Created by Darth Butterwell on 8/7/20.
//

#include "expand.h"

int 	validate_double_quote(t_handle *handle)
{
	t_state state;
	char c;

	state = e_unset;
	c = handle->raw[handle->index];
	if (c == '!')
		state = e_bang;
	else if (c == '$')
		state = e_dollar;
	else if (c == '\\')
		state = e_back_slash;
	else if (c == '\"')
		vec_rm_last(handle->states);
	if (state != e_unset)
		vec_push(handle->states, &state);
	return (0);
}