/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 16:07:50 by dbutterw          #+#    #+#             */
/*   Updated: 2020/01/06 14:39:22 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_vec.h"

int vec_del(t_vec **vector)
{
	size_t	cnt;
	t_vec	*tmp;

	if (!vector || !*vector)
		return (VEC_DNE);
	cnt = 0;
	tmp = *vector;
	if (tmp->del)
		while (cnt < tmp->size)
			vec_del_one(tmp, cnt++);
	free(tmp->data);
	free(tmp);
	return (VEC_OK);
}
