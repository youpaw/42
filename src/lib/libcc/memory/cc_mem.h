//
// Created by youpaw on 05.05.2020.
//

#ifndef CC_MEM_H
# define CC_MEM_H
# include <stddef.h>

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

#endif //CC_MEM_H
