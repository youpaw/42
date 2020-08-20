/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nstrjoin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 21:17:44 by dbutterw          #+#    #+#             */
/*   Updated: 2019/11/25 20:06:09 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "cc_str.h"
#include "memory/cc_mem.h"

char		*nstrjoin(int n, ...)
{
	va_list		argptr;
	int			n_cpy;
	size_t		len;
	char		*ptr;
	char		*str;

	n_cpy = n;
	len = 0;
	va_start(argptr, n);
	while (n--)
	{
		ptr = va_arg(argptr, char *);
		len += strlen(ptr);
	}
	va_end(argptr);
	str = (char *)xmalloc(len + 1);
	bzero(str, len + 1);
	va_start(argptr, n);
	while (n_cpy--)
	{
		ptr = va_arg(argptr, char *);
		str = strcat(str, ptr);
	}
	va_end(argptr);
	return (str);
}
