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
# undef strcpy
# undef strdup
# undef strlen
# undef isspace

char 		*strnew(size_t size);
int			strcmp(const char *s1, const char *s2);
char		*nstrjoin(int n, ...);
char 		*strstr(const char *haystack, const char *needle);
char		*strcpy(char *dst, const char *src);
char		*strdup(const char *s1);
size_t		strlen(const char *s);
char		*strcat(char *s1, const char *s2);
long long	atoll(const char *str);
int			isspace(int c);

/*
**	mems
*/

# undef xmalloc
# undef memset
# undef memmove
# undef bzero

void		*xmalloc(size_t size);
void		*memset(void *b, int c, size_t len);
void		*memmove(void *dst, const void *src, size_t len);
void		bzero(void *s, size_t n);

/*
**	Writes
*/



#endif
