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
	void			**data;
	size_t			datasize;
	size_t			capacity;
	size_t			size;
}					t_vec;

t_vec				*vec_new(size_t capacity, size_t datasize);
void				vec_push(t_vec *vector, void *data);
size_t				vec_rm_last(t_vec *vector);
size_t				vec_rm_at(t_vec *vector, size_t index);
void				*vec_get_last(t_vec *vector);
void				*vec_get_at(t_vec *vector, size_t index);
void				vec_del(t_vec **vector);

#endif //CC_VEC_H
