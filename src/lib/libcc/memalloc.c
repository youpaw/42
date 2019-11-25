/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memalloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 19:55:14 by dbutterw          #+#    #+#             */
/*   Updated: 2019/11/25 19:55:55 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc.h"

void	*memalloc(size_t size)
{
	void	*ptr;

	ptr = xmalloc(size);
	if (!ptr)
		return (NULL);
	bzero(ptr, size);
	return (ptr);
}
