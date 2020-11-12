//
// Created by Azzak Omega on 8/29/20.
//

#include "alias.h"
#include "cc_hash_map.h"

const char	*alias_get_value(const char *key)
{
	return (hash_map_get_val(g_aliases, key));
}
