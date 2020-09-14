//
// Created by Azzak Omega on 9/10/20.
//

#include "hash.h"

static t_hash_bin_pair *get_bin_pair(const char *bin)
{
	return hash_map_get_val(g_hash, bin);
}

const char *hash_get_path(const char *bin)
{
	t_hash_bin_pair *bin_pair;
	char 			*path;

	if ((bin_pair = get_bin_pair(bin)) && ++(bin_pair->count))
		return (bin_pair->path);
	if (!(path = hash_get_bin_path(bin)))
		return (NULL);
	hash_insert(bin, path);
	free(path);
	return (hash_get_path(bin));
}