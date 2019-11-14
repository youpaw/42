#include <stdlib.h>
#include <unistd.h>
void		*xmalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr)
		return (ptr);
	write(2, "malloc() failed, exit...\n", 25);
	exit(EXIT_FAILURE);
}