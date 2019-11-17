#ifndef LIBCC_H
# define LIBCC_H

# include <stddef.h>

// TODO implement the following functions in cc lib:

// strings
/*
 * strcpy
 * strcat
 *
 */

// mem
/*
 * memcpy, memmove etc.
 *
 *
 */

// ####################################################

/*
**	strings
*/

# undef strnew
# undef	strcmp
# undef nstrjoin
# undef strstr

char 		*strnew(size_t size);
int			strcmp(const char *s1, const char *s2);
char		*nstrjoin(int n, ...);
char 		*strstr(const char *haystack, const char *needle);
long long	atoll(const char *str);

/*
**	mems
*/

# undef xmalloc
# undef memset

void		*xmalloc(size_t size);
void		*memset(void *b, int c, size_t len);

/*
**	Writes
*/



#endif
