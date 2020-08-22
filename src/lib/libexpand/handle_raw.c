//
// Created by youpaw on 6/14/20.
//

#include "expand.h"
#include <stdlib.h>
#include "cc_mem.h"
#include "cc_str.h"

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

static void 	del_expand(t_handle *handle)
{
	vec_del(&(handle->states));
	free(handle);
}

static void		clear_str(t_handle *handle)
{
	size_t padding;

	handle->index = 0;
	padding = 0;
	while (handle->index < handle->size)
	{
		if (handle->raw[handle->index])
			handle->raw[padding++] = handle->raw[handle->index++];
		else
			handle->index++;
	}
	handle->raw[padding] = '\0';
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
	if (!error)
		clear_str(handle);
	del_expand(handle);
	return (error);
}
