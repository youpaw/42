//
// Created by Azzak Omega on 8/29/20.
//

#include "alias.h"
#include "env.h"
#include "cc_str.h"

t_hash_map *g_aliases;

void		alias_init(void)
{
	g_aliases = hash_map_new(N_MAX_ALIAS, (size_t (*)(const void *)) &strhash, \
		(int (*)(const void *, const void *)) &env_cmp_pair, &env_del_pair);
}
