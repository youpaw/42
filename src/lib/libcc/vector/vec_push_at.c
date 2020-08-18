//
// Created by Darth Butterwell on 8/18/20.
//

#include "cc_vec.h"
#include "memory/cc_mem.h"

int			vec_push_at(t_vec *vector, void *data, size_t index)
{
	void	*pdata;

	if (!vector)
		return (VEC_DNE);
	if (index > vector->size)
		return (VEC_OOB);
	if (vector->size >= vector->capacity)
	{
		pdata = vector->data;
		vector->data = xmalloc(vector->datasize * (vector->capacity * 2 + 1));
		memmove(vector->data, pdata, vector->datasize * (vector->capacity + 1));
		free(pdata);
		vector->capacity *= 2;
	}
	pdata = vector->data + (index * vector->datasize);
	if (index < vector->size)
		memmove(pdata + vector->datasize, pdata, vector->datasize * (vector->size - index));
	memmove(pdata, data, vector->datasize);
	vector->size++;
	bzero(vector->data + (vector->size * vector->datasize), vector->datasize);
	return (VEC_OK);
}