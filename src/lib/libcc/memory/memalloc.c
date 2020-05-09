/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memalloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 19:55:14 by dbutterw          #+#    #+#             */
/*   Updated: 2019/11/25 20:06:13 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_mem.h"

void	*memalloc(size_t size)
{
	void	*ptr;

	ptr = xmalloc(size);
	bzero(ptr, size);
	return (ptr);
}
