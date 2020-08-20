/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:04:12 by dbutterw          #+#    #+#             */
/*   Updated: 2020/08/20 19:27:34 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_vec.h"

int vec_push(t_vec *vector, void *data)
{
	return (vec_push_at(vector, data, vector->size));
}
