/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 18:50:43 by dbutterw          #+#    #+#             */
/*   Updated: 2020/01/06 14:39:22 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_vec.h"
#include "cc_mem.h"

t_vec	*vec_init(size_t capacity, size_t datasize)
{
	t_vec *vector;

	vector = (t_vec*)xmalloc(sizeof(t_vec));
	vector->data = xmalloc(datasize * capacity + datasize);
	bzero(vector->data, datasize * capacity + datasize);
	vector->datasize = datasize;
	vector->capacity = capacity;
	vector->size = 0;
	return (vector);
}
