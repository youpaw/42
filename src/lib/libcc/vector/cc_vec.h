/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cc_vec.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 17:23:43 by dbutterw          #+#    #+#             */
/*   Updated: 2020/07/17 17:23:43 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CC_VEC_H
# define CC_VEC_H
# include <stdlib.h>

typedef struct		s_vec
{
	void			*data;
	size_t			datasize;
	size_t			capacity;
	size_t			size;
	void			(*del)(void *);
}					t_vec;

t_vec				*vec_new(size_t capacity, size_t datasize, void (*del)(void *));
int					vec_push(t_vec *vector, void *data);
size_t				vec_rm_last(t_vec *vector);
size_t				vec_rm_at(t_vec *vector, size_t index);
int					vec_get_last(void *dst, t_vec *vector);
int					vec_get_at(void *dst, t_vec *vector, size_t index);
int					vec_del(t_vec **vector);
int					vec_del_one(t_vec *vector, size_t index);

#define VEC_OK 0
#define VEC_DNE VEC_OK + 1
#define VEC_OOB VEC_DNE + 1

#endif //CC_VEC_H
