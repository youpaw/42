//
// Created by youpaw on 6/21/20.
//

#include "cc_hash_map.h"

static int 		del_item(t_list *bucket, const void *key, \
	int (*cmp)(const void *, const void *), void (*del)(t_hash_pair *))
{
	t_list *prev;

	prev = NULL;
	while (bucket && cmp(((t_hash_pair*)(bucket->content))->key, key))
		bucket = bucket->next;
	if (!bucket)
		return (1);
	if (prev)
		prev->next = bucket->next;
	lst_del_one(&bucket, (void (*)(void *)) del);
	return (0);
}

int 			hash_map_del_one(t_hash_table *table, const void *key)
{
	size_t index;

	index = table->hasher(key);
	if (index >= table->size)
		return (1);
	return (del_item(table->buckets[index], key, table->cmp, table->del));
}