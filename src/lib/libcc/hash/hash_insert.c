//
// Created by youpaw on 6/21/20.
//

#include "cc_hash.h"
#include "memory/cc_mem.h"

static void		replace_item(t_list *item, t_hash_pair *pair, void (*del)(t_hash_pair *))
{
	if (!item)
		return ;
	del(item->content);
	memmove(item->content, pair, item->size);
}

static t_list	*get_item(t_list *bucket, void *key, \
	int (*cmp)(const void *, const void *))
{
	while (bucket && cmp(((t_hash_pair*)(bucket->content))->key, key))
		bucket = bucket->next;
	return (bucket);
}

int				hash_insert(t_hash_table *table, t_hash_pair *pair)
{

	size_t index;
	t_list *bucket;
	t_list *item;

	if ((index = table->hasher(pair->key)) >= table->size)
		return (1);
	if (!(bucket = table->buckets[index]))
		bucket = lst_new(pair, sizeof(t_hash_pair));
	else if ((item = get_item(bucket, pair->key, table->cmp)))
		replace_item(item, pair, table->del);
	else
		lst_add(&bucket, lst_new(pair, sizeof(t_hash_pair)));
	return (0);
}