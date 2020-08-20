//
// Created by youpaw on 09.05.2020.
//

#include "cc_vec.h"
#include "memory/cc_mem.h"

size_t	vec_rm_at(t_vec *vector, size_t index)
{
	void *pdata;

	if (!vector || !vector->size)
		return (0);
	if (index >= vector->size)
		return (vector->size);
	if (vector->del)
		vec_del_one(vector, index);
	pdata = vector->data + (index * vector->datasize);
	if (index < (vector->size - 1))
		memmove(pdata, pdata + vector->datasize, (vector->size - index) * vector->datasize);
	else
		bzero(pdata, vector->datasize);
	vector->size--;
	return (vector->size);
}
