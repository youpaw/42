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
	void	**tmp;
	size_t	cnt;

	if (!vector)
		return ;
	if (vector->size >= vector->capacity)
	{
		tmp = vector->data;
		vector->data = (void **)xmalloc(vector->datasize * vector->capacity * 2 + vector->datasize);
		cnt = -1;
		while (++cnt < vector->size)
				vector->data[cnt] = tmp[cnt];
		free(tmp);
		vector->capacity *= 2;
	}
	vector->data[vector->size] = data;
	vector->size++;
	vector->data[vector->size] = NULL;
}
