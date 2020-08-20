//
// Created by youpaw on 6/21/20.
//

#include "cc_hash_map.h"

void 			*hash_map_get_val(t_hash_table *table, const void *key)
{
	t_hash_pair *pair;

	pair = hash_map_get_pair(table, key);
	if (pair)
		return (pair->value);
	return (NULL);
}