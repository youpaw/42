//
// Created by youpaw on 6/24/20.
//

#include <stddef.h>

size_t		strhash(const unsigned char *str)
{
	size_t hash;
	int c;

	hash = 5381;
	while ((c = *str++))
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	return (hash);
}
