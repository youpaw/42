//
// Created by Azzak Omega on 8/29/20.
//

#include "stdlib.h"
#include "cc_str.h"

void			arr2_del(char **m)
{
	if (m)
		while (*m)
			free(*m++);
}

size_t			arr2_get_size(const char **m)
{
	size_t	len;

	len = 0;
	if (m)
		while (*m++)
			len++;
	return (len);
}

void			arr2_print(const char **args, const char *st, const char *en)
{
	const char *start = "";
	const char *end = "\n";

	if (args)
	{
		if (st)
			start = st;
		if (en)
			end = en;
		while (*args)
		{
			puts(start);
			puts(*args++);
			puts(end);
		}
	}
}