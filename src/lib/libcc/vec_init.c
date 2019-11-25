//
// Created by Gillam Hazrak zo loraq on 25/11/2019.
//

#include "cc.h"

t_vec	*vec_init(size_t capacity)
{
	t_vec *vec;

	if (!capacity || !(vec = (t_vec *)malloc(sizeof(t_vec))))
		return (NULL);
	if (!(vec->data = malloc(sizeof(void *) * capacity)))
	{
		free(vec);
		return (NULL);
	}
	vec->capacity = capacity;
	vec->total = 0;
	return (vec);
}
