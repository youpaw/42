//
// Created by youpaw on 09.05.2020.
//

#include "cc_vec.h"
#include "memory/cc_mem.h"

int		vec_get_at(void *dst, t_vec *vector, size_t index)
{
	if (!vector)
		return (VEC_DNE);
	if (!vector->size || index >= vector->size)
		return (VEC_OOB);
	memmove(dst, vector->data + (index * vector->datasize), vector->datasize);
	return (VEC_OK);
}