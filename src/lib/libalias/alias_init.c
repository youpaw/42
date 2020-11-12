//
// Created by Azzak Omega on 8/29/20.
//

#include "alias.h"
#include "cc_str.h"

t_hash_map *g_aliases;

void		alias_init(void)
{
	g_aliases = hash_map_new(N_MAX_ALIAS, (size_t (*)(const void *)) &strhash, \
		(int (*)(const void *, const void *)) &alias_cmp_pair, &alias_del_pair);
}
