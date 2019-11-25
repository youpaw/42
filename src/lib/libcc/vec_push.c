//
// Created by Gillam Hazrak zo loraq on 25/11/2019.
//

#include "cc.h"

t_vec	*vec_push(t_vec *vec, void *content)
{
	void	*tmp;

	if (!vec)
		return (NULL);
	tmp = vec->data;
	if (vec->total >= vec->capacity)
	{
		if (!(vec->data = malloc(sizeof(void *) * (vec->capacity * 2))))
		{
			free(tmp);
			free(vec);
			return (NULL);
		}
		vec->capacity *= 2;
		memmove(vec->data, tmp, sizeof(void *) * vec->total);
		free(tmp);
		(((void **)vec->data))[vec->total] = strdup(content);
		vec->total += 1;
	}
	else
	{
		(((void **)vec->data))[vec->total] = strdup(content);
		vec->total += 1;
	}
	return (vec);
}
