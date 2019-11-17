#include "cc.h"

char 		*strnew(size_t size)
{
	char	*res;

	res = xmalloc(size + 1);
	memset(res, 0, size + 1);
	return (res);
}