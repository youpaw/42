#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "cc.h"

/*
**	(const) char * args are binded in one string
*/

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