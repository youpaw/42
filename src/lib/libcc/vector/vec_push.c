/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:04:12 by dbutterw          #+#    #+#             */
/*   Updated: 2020/01/06 14:39:22 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_vec.h"
#include "cc_mem.h"

int vec_push(t_vec *vector, void *data)
{
	void	*pdata;

	if (!vector)
		return (VEC_DNE);
	if (vector->size >= vector->capacity)
	{
		pdata = vector->data;
		vector->data = xmalloc(vector->datasize * (vector->capacity * 2 + 1));
		memmove(vector->data, pdata, vector->datasize * (vector->capacity + 1));
		free(pdata);
		vector->capacity *= 2;
	}
	memmove(vector->data + (vector->size * vector->datasize), data, vector->datasize);
	vector->size++;
	bzero(vector->data + (vector->size * vector->datasize), vector->datasize);
	return (VEC_OK);
}
