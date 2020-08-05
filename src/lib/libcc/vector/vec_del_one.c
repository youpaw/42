//
// Created by Darth Butterwell on 8/2/20.
//

#include "cc_vec.h"
#include "memory/cc_mem.h"

int vec_del_one(t_vec *vector, size_t index)
{
	void *data;

	if (!vector)
		return (VEC_DNE);
	if (index >= vector->size)
		return (VEC_OOB);
	data = xmalloc(vector->datasize);
	memmove(data, vector->data + (index * vector->datasize), vector->datasize);
	vector->del(data);
	free(data);
	return (VEC_OK);
}