#include <stdlib.h>

ssize_t min(ssize_t x, ssize_t y)
{
	if (x > y)
		return (y);
	return (x);
}
