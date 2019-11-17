#include <stddef.h>

void				*memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*uc;

	i = 0;
	uc = (unsigned char*)b;
	while (i < len)
		uc[i++] = (unsigned char)c;
	return (uc);
}
