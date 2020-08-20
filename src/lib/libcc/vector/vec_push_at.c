/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_push_at.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 13:36:37 by mgena             #+#    #+#             */
/*   Updated: 2020/08/20 19:27:34 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_vec.h"
#include "cc_mem.h"

int					vec_push_at(t_vec *vector, void *data, size_t index)
{
	void	*pdata;

	if (!vector)
		return (VEC_DNE);
	if (vector->size >= vector->capacity)
	{
		pdata = vector->data;
		vector->data = xmalloc(vector->datasize * (vector->capacity * 2 + 1));
		memmove(vector->data, pdata, vector->datasize *(vector->capacity + 1));
		free(pdata);
		vector->capacity *= 2;
	}
	memmove(vector->data + ((index + 1) * vector->datasize), vector->data + ((index) * vector->datasize),
		 (vector->size - index) * vector->datasize);
	memmove(vector->data + ((index) * vector->datasize), data, vector->datasize);
	vector->size++;
	bzero(vector->data + (vector->size * vector->datasize), vector->datasize);
	return VEC_OK;
}

