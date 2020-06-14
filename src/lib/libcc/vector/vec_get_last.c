//
// Created by youpaw on 09.05.2020.
//

#include "cc_vec.h"

void	*vec_get_last(t_vec *vector)
{
	if (!vector || !vector->size)
		return (NULL);
	return (vec_get_at(vector, vector->size-1));
}
