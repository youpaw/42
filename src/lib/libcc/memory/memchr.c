/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 00:06:49 by dbutterw          #+#    #+#             */
/*   Updated: 2020/08/20 19:30:12 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*memchr(const void *s, int c, size_t n)
{
	unsigned char	*ts;
	unsigned char	t;

	ts = (unsigned char *)s;
	t = (unsigned char)c;
	while (n--)
	{
		if (*ts == t)
			return ((void*)ts);
		ts++;
	}
	return (NULL);
}
