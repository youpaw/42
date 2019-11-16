#ifndef LIBCC_H
# define LIBCC_H

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
**
*/

# undef	strcmp
# undef nstrjoin
# undef strstr

int			strcmp(const char *s1, const char *s2);
char		*nstrjoin(int n, ...);
char 		*strstr(const char *haystack, const char *needle);

/*
**
*/

# undef xmalloc

size_t		xmalloc(size_t size);

#endif
