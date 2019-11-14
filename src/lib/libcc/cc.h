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

int			strcmp(const char *s1, const char *s2);
char		*nstrjoin(int n, ...);

/*
**
*/

# undef xmalloc

size_t		xmalloc(size_t size);

#endif
