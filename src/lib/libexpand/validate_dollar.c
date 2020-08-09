//
// Created by Darth Butterwell on 8/7/20.
//
#include "expand.h"

static int match_brace(t_handle *handle, t_brace brace)
{
	int		error;
	t_state current;
	t_vec	*braces;

	braces = vec_new(BRACES_STACK_SIZE, sizeof(t_brace), NULL);
	vec_push(braces, &brace);
	while (handle->index < handle->size && braces->size)
	{
		current = get_current_state(handle);
		if ((error = handle_all(handle, current)))
			break ;
		if (current == e_unset && get_brace(&(handle->raw[handle->index]), &brace))
		{

		}
		handle->index++;
	}
	return (E_INCOMPLETE_INPUT);
}

int 	validate_dollar(t_handle *handle)
{
	t_brace	brace;
	t_state state;
	int		error;

	error = 0;
	if (get_brace((&handle->raw[handle->index]), &brace) >= 0)
	{
		state = e_unset;
		vec_push(handle->states, &state);
		handle->index++;
		if (brace == e_double_round_brace)
			handle->index++;
		error = match_brace(handle, brace);
		vec_rm_last(handle->states);
	}
	vec_rm_last(handle->states);
	return (error);
}
