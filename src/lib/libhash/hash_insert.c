//
// Created by Azzak Omega on 9/10/20.
//

#include "hash.h"
#include "cc_hash_map.h"
#include "cc_str.h"
#include "cc_mem.h"

int 	hash_insert(const char *bin, const char *path)
{
	t_hash_pair	pair;

	if (!bin || !path)
		return (1);
	pair.key = strdup(bin);
	pair.value = (t_hash_bin_pair *)xmalloc(sizeof(t_hash_bin_pair));
	((t_hash_bin_pair *)pair.value)->path = strdup(path);
	((t_hash_bin_pair *)pair.value)->count = 0;
	return (hash_map_insert(g_hash, &pair));
}
