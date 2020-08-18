/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cc_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 17:23:06 by dbutterw          #+#    #+#             */
/*   Updated: 2020/07/25 16:44:08 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CC_STR_H
# define CC_STR_H
# include <stddef.h>

# undef fdputendl
# undef fdputs
# undef itoa
# undef itoabase
# undef nstrjoin
# undef putendl
# undef puts
# undef strcat
# undef strchr
# undef strclr
# undef strcmp
# undef strcpy
# undef strdel
# undef strdup
# undef strequ
# undef strhash
# undef striter
# undef striteri
# undef strjoin
# undef strlcat
# undef strlen
# undef strmap
# undef strmapi
# undef strncat
# undef strncmp
# undef strncpy
# undef strneq
# undef strnew
# undef strnstr
# undef strrchr
# undef strsplit
# undef strsplitcharset
# undef strstr
# undef strsub
# undef strtrim

void		fdputendl(char const *s, int fd);
int			fdputs(const char *restrict s, int stream);
char		*itoa(long long int n);
char		*itoabase(size_t n, size_t base, char reg);
char		*nstrjoin(int n, ...);
void		putendl(char const *s);
int			puts(char const *s);
char		*strcat(char *s1, const char *s2);
char		*strchr(const char *s, int c);
void		strclr(char *s);
int			strcmp(const char *s1, const char *s2);
char		*strcpy(char *dst, const char *src);
void		strdel(char **as);
char		*strdup(const char *s1);
int			strequ(char const *s1, char const *s2);
size_t		strhash(const unsigned char *str);
void		striter(char *s, void (*f)(char *));
void		striteri(char *s, void (*f)(unsigned int, char *));
char		*strjoin(char const *s1, char const *s2);
size_t		strlcat(char *dst, const char *src, size_t size);
size_t		strlen(const char *s);
char		*strmap(char const *s, char (*f)(char));
char		*strmapi(char const *s, char (*f)(unsigned int, char));
char 		*strncat(char *s1, const char *s2, size_t n);
int			strncmp(const char *s1, const char *s2, size_t n);
char		*strncpy(char *dest, const char *src, size_t n);
int			strnequ(char const *s1, char const *s2, size_t n);
char 		*strnew(size_t size);
char		*strnstr(const char *haystack, const char *needle, size_t len);
char		*strrchr(const char *s, int c);
char		**strsplit(char const *s);
char		**strsplitcharset(char const *s, char *charset);
char 		*strstr(const char *haystack, const char *needle);
char		*strsub(char const *s, unsigned int start, size_t len);
char		*strtrim(char const *s);

#endif //CC_STR_H
