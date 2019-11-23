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
**	chars
*/

# undef isspace

int			isspace(int c);

/*
**	strings
*/

# undef strnew
# undef	strcmp
# undef strncmp
# undef nstrjoin
# undef strstr
# undef strcpy
# undef strncpy
# undef strdup
# undef strlen

char 		*strnew(size_t size);
size_t		strlen(const char *s);
char		*strdup(const char *s1);
int			strcmp(const char *s1, const char *s2);
int			strncmp(const char *s1, const char *s2, size_t n);
char		*strcpy(char *dst, const char *src);
char		*strncpy(char *dest, const char *src, size_t n);
char		*strcat(char *s1, const char *s2);
char		*nstrjoin(int n, ...);
char		*strsub(char const *s, unsigned int start, size_t len);
char 		*strstr(const char *haystack, const char *needle);
long long	atoll(const char *str);

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

int			fdputs(const char *restrict s, int stream);

#endif
