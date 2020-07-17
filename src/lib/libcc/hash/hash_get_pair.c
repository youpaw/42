//
// Created by youpaw on 6/21/20.
//

#include "cc_hash.h"

t_hash_pair 			*hash_get_pair(t_hash_table *table, const void *key)
{
	t_list *item;

	item = hash_get(table, key);
	if (item)
		return (item->content);
	return (NULL);
}