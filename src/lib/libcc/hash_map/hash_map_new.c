//
// Created by youpaw on 6/21/20.
//
#include "cc_hash_map.h"
#include "memory/cc_mem.h"

t_hash_table 	*hash_map_new(size_t n_buckets, \
	size_t (*hasher)(const void *), \
	int (*cmp)(const void *, const void *), \
	void 	(*del)(t_hash_pair *))
{
	t_hash_table *table;
	size_t cnt;

	if (!hasher || !cmp || !n_buckets)
		return (NULL);
	table = xmalloc(sizeof(t_hash_table));
	table->buckets = (t_list **)xmalloc(sizeof(t_list*) * n_buckets);
	cnt = 0;
	while (cnt < n_buckets)
		table->buckets[cnt++] = NULL;
	table->hasher = hasher;
	table->cmp = cmp;
	table->del = del;
	table->size = n_buckets;
	return (table);
}