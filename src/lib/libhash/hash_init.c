//
// Created by Azzak Omega on 9/10/20.
//

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
