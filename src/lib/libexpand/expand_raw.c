//
// Created by youpaw on 6/14/20.
//

#include "expand.h"
#include <stdlib.h>
#include "memory/cc_mem.h"
#include "string/cc_str.h"

static t_handle *init_expand(char *raw, t_stage stage)
{
	t_handle	*handle;
	t_state		state;

	handle = xmalloc(sizeof(t_handle));
	handle->raw = raw;
	handle->index = 0;
	handle->size = strlen(raw);
	handle->states = vec_new(STATES_STACK_SIZE, sizeof(t_state), NULL);
	handle->stage = stage;
	bzero(handle->flags, sizeof(char) * N_EXPAND_FLAGS);
	state = e_unset;
	vec_push(handle->states, &state);
	return (handle);
}

static void 	del_expand(char **raw, t_handle *expand)
{
	*raw = expand->raw;
	vec_del(&(expand->states));
	free(expand);
}

int				handle_raw(char **raw, t_stage stage)
{
	t_handle	*handle;
	t_state		current;
	int			error;

	if (!raw || !*raw || !**raw)
		return (E_NULL_INPUT);
	error = 0;
	handle = init_expand(*raw, stage);
	while (handle->index < handle->size)
	{
		current = get_current_state(handle);
		if ((error = handle_all(handle, current)))
			break ;
		handle->index++;
	}
	if (!error && handle->states->size > 1)
		error = E_INCOMPLETE_INPUT;
	del_expand(raw, handle);
	return (error);
}
