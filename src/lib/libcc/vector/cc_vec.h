//
// Created by youpaw on 29.02.2020.
//

#ifndef CC_VEC_H
# define CC_VEC_H
# include <stdlib.h>

typedef struct		s_vec
{
	void			*data;
	size_t			datasize;
	size_t			capacity;
	size_t			size;
}					t_vec;

t_vec				*vec_init(size_t capacity, size_t datasize);
void				vec_push(t_vec *vector, void *data);
size_t				vec_rm_last(t_vec *vector);
size_t				vec_rm_at(t_vec *vector, size_t index);
void				*vec_get_last(t_vec *vector);
void				*vec_get_at(t_vec *vector, size_t index);
void				vec_del(t_vec **vector);

#endif //CC_VEC_H
