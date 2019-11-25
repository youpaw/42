#ifndef LIBCC_H
# define LIBCC_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

// TODO implement the following functions in cc lib:

/*
**	chars
*/

# undef isspace
# undef isdigit

int			isspace(int c);
int			isdigit(int c);

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
# undef	atoll
# undef strchr

char 		*strnew(size_t size);
size_t		strlen(const char *s);
char		*strdup(const char *s1);
int			strcmp(const char *s1, const char *s2);
int			strncmp(const char *s1, const char *s2, size_t n);
char		*strcpy(char *dst, const char *src);
char		*strncpy(char *dest, const char *src, size_t n);
char		*strcat(char *s1, const char *s2);
char		*strchr(const char *s, int c);
char		*nstrjoin(int n, ...);
char		*strsub(char const *s, unsigned int start, size_t len);
char 		*strstr(const char *haystack, const char *needle);
char		*strtrim(char const *s);
char		**strsplitcharset(char const *s, char *charset);
long long	atoll(const char *str);

/*
**	mems
*/

# undef xmalloc
# undef memset
# undef memmove
# undef memcpy
# undef bzero

void		*xmalloc(size_t size);
void		*memset(void *b, int c, size_t len);
void		*memcpy(void *dst, const void *src, size_t n);
void		*memmove(void *dst, const void *src, size_t len);
void		*memalloc(size_t size);
void		bzero(void *s, size_t n);

/*
**	Writes
*/

int			fdputs(const char *restrict s, int stream);

/*
** Vector
*/

typedef struct	s_vec
{
	void		*data;
	size_t		capacity;
	size_t		total;
}				t_vec;

t_vec			*vec_init(size_t capacity);
t_vec			*vec_push(t_vec *vec, void *content);

#endif
