//
// Created by youpaw on 09.05.2020.
//

#include "cc_vec.h"

int		vec_get_last(void *dst, t_vec *vector)
{
	if (!vector)
		return (VEC_DNE);
	if (!vector->size)
		return (VEC_OOB);
	return (vec_get_at(dst, vector, vector->size-1));
}
