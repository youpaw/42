//
// Created by Darth Butterwell on 8/2/20.
//

#include "cc_vec.h"
#include "memory/cc_mem.h"

void				vec_del_one(t_vec *vector, size_t index)
{
	void *data;

	data = xmalloc(vector->datasize);
	memmove(data, vector->data + (index * vector->datasize), vector->datasize);
	vector->del(data);
	free(data);
}