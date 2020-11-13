/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:54:24 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:54:26 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_H
# define HASH_H
# define N_MAX_HASH 100

# include "cc_hash_map.h"

extern t_hash_map	*g_hash;

typedef struct		s_hash_bin_pair
{
	size_t		count;
	char		*path;
}					t_hash_bin_pair;

void				hash_init();
int					hash_print(void);
int					hash_insert(const char *bin, const char *path);
const char			*hash_get_path(const char *bin);
void				hash_del(void);

char				*hash_get_bin_path(const char *bin);

#endif
