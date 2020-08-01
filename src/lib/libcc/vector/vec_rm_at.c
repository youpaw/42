//
// Created by youpaw on 09.05.2020.
//

#include "cc_vec.h"
#include "cc_mem.h"

size_t	vec_rm_at(t_vec *vector, size_t index)
{
	size_t cnt;

	if (!vector || !vector->size)
		return (0);
	if (index >= vector->size)
		return (vector->size);
	if (index < (vector->size - 1))
	{
		cnt = index + 1;
		while (cnt <= vector->size)
			vector->data[index++] = vector->data[cnt++];
	}
	vector->size--;
	return (vector->size);
}
