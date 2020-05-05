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

void	vec_push(t_vec *vector, void *data)
{
	void *pdata;

	if (!vector)
		return ;
	if (vector->size >= vector->capacity)
	{
		pdata = vector->data;
		vector->data = \
		xmalloc(vector->datasize * vector->capacity * 2 + vector->datasize);
		vector->data = memcpy(vector->data, pdata, \
		vector->datasize * vector->capacity);
		free(pdata);
		pdata = vector->data + vector->datasize * (vector->capacity + 1);
		bzero(pdata, vector->datasize * vector->capacity);
		vector->capacity *= 2;
	}
	pdata = vector->data + vector->size * vector->datasize;
	memcpy(pdata, data, vector->datasize);
	vector->size++;
}
