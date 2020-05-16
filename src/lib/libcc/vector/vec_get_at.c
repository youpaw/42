//
// Created by youpaw on 09.05.2020.
//

#include "cc_vec.h"

void	*vec_get_at(t_vec *vector, size_t index)
{
	if (!vector || !vector->size || index >= vector->size)
		return (NULL);
	return (vector->data + index * vector->datasize);
}