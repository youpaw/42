/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cc_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 17:23:06 by dbutterw          #+#    #+#             */
/*   Updated: 2020/08/20 19:27:34 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CC_STR_H
# define CC_STR_H
# include <stddef.h>

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
# undef strhash

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
char		*strnstr(const char *haystack, const char *needle, size_t len);
char		*strtrim(char const *s);
char		**strsplitcharset(char const *s, char *charset);
long long	atoll(const char *str);
int			fdputs(const char *restrict s, int stream);
size_t		strhash(const unsigned char *str);
#endif //CC_STR_H
