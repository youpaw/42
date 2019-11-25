/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 19:48:50 by dbutterw          #+#    #+#             */
/*   Updated: 2019/11/25 20:06:09 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *td;
	unsigned char *ts;

	td = (unsigned char*)dst;
	ts = (unsigned char*)src;
	if (!dst && !src)
		return (NULL);
	while (n--)
		*td++ = *ts++;
	return (dst);
}
