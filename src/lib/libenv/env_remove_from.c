//
// Created by Azzak Omega on 8/26/20.
//

#include "cc_hash_map.h"
int		env_remove_from(t_hash_map *hm, const char *key)
{
	if (!hm || !key)
		return (1);
	return (hash_map_del_one(hm, key));
}
