//
// Created by Darth Butterwell on 8/7/20.
//

#include "expand.h"
#include "string/cc_str.h"

int 	validate_back_slash(t_handle *handle)
{
	char c;

	c = handle->raw[handle->index];
	if (c == '\n')
	{
		if (handle->index == handle->size - 1)
			return (E_INCOMPLETE_INPUT);
		strcpy(handle->raw + handle->index - 1, \
		handle->raw + handle->index + 1);
		handle->size -= 2;
		handle->index -= 2;
	}
	vec_rm_last(handle->states);
	return (0);
}