//
// Created by Azzak Omega on 8/29/20.
//

#include "cc_hash_map.h"
#include "alias.h"

int 		alias_remove(const char *key)
{
	if (!key)
		return (1);
	return (hash_map_del_one(g_aliases, key));
}
