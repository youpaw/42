/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 18:50:43 by dbutterw          #+#    #+#             */
/*   Updated: 2020/08/22 14:48:26 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_vec.h"
#include "memory/cc_mem.h"

t_vec	*vec_new(size_t capacity, size_t datasize, void (*del)(void *))
{
	t_vec	*vector;

	vector = (t_vec*)xmalloc(sizeof(t_vec));
	vector->data = xmalloc(datasize * (capacity + 1));
	vector->capacity = capacity;
	vector->datasize = datasize;
	vector->size = 0;
	vector->del = del;
	bzero(vector->data, datasize);
	return (vector);
}
