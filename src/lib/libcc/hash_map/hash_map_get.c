//
// Created by youpaw on 6/21/20.
//

#include "cc_hash_map.h"

static t_list	*get_item(t_list *bucket, const void *key, \
	int (*cmp)(const void *, const void *))
{
	while (bucket && cmp(((t_hash_pair*)(bucket->content))->key, key))
		bucket = bucket->next;
	return (bucket);
}

t_list 			*hash_map_get(t_hash_table *table, const void *key)
{
	size_t index;

	index = table->hasher(key) % table->size;
	return (get_item(table->buckets[index], key, table->cmp));
}
