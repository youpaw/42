/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 20:45:47 by dbutterw          #+#    #+#             */
/*   Updated: 2019/11/25 20:06:09 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmpdst;
	unsigned char	*tmpsrc;

	if (!src && !dst)
		return (NULL);
	tmpdst = (unsigned char*)dst;
	tmpsrc = (unsigned char*)src;
	if (tmpsrc < tmpdst)
		while (len--)
			*(tmpdst + len) = *(tmpsrc + len);
	else
		while (len--)
			*tmpdst++ = *tmpsrc++;
	return (dst);
}
