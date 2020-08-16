//
// Created by Darth Butterwell on 8/7/20.
//

#include "expand.h"
#include "memory/cc_mem.h"

int 	validate_back_slash(t_handle *handle)
{
	char c;

	c = handle->raw[handle->index];
	if (c == '\n')
	{
		if (handle->index == handle->size - 1)
			return (E_INCOMPLETE_INPUT);
		bzero(handle->raw + handle->index - 1, 2);
	}
	vec_rm_last(handle->states);
	return (0);
}