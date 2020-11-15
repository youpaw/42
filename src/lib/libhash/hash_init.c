/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <azomega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:15 by azomega           #+#    #+#             */
/*   Updated: 2020/11/14 15:11:11 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"
#include "cc_hash_map.h"
#include "cc_str.h"

t_hash_map *g_hash;

static int		hash_cmp_bin(const t_hash_pair *lhs, const t_hash_pair *rhs)
{
	return (strcmp(lhs->key, rhs->key));
}

static void		hash_del_bin(t_hash_pair *pair)
{
	free(pair->key);
	free(((t_hash_bin_pair *)pair->value)->path);
	free(pair->value);
}

void			hash_init(void)
{
	g_hash = hash_map_new(N_MAX_HASH, (size_t (*)(const void *)) &strhash, \
		(int (*)(const void *, const void *)) &hash_cmp_bin, &hash_del_bin);
}
