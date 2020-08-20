/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 21:17:21 by dbutterw          #+#    #+#             */
/*   Updated: 2019/11/25 20:06:09 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory/cc_mem.h"

char		*strnew(size_t size)
{
	char	*res;

	if (!(size + 1))
		return (NULL);
	res = xmalloc(size + 1);
	memset(res, 0, size + 1);
	return (res);
}
