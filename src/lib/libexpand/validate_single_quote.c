//
// Created by Darth Butterwell on 8/7/20.
//
#include "expand.h"

int 	validate_single_quote(t_handle *handle)
{
	while (handle->raw[handle->index] != '\'' && handle->index < handle->size)
		handle->index++;
	if (handle->index == handle->size)
		return (E_INCOMPLETE_INPUT);
	vec_rm_last(handle->states);
	return (0);
}