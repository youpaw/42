//
// Created by youpaw on 6/24/20.
//
#include "cc_hash_map.h"

void 			hash_map_iter(t_hash_table *table, void (*f)(void *value))
{
	t_list *tmp;
	t_hash_pair *pair;
	size_t cnt;

	cnt = 0;
	while (cnt < table->size)
	{
		tmp = table->buckets[cnt];
		while (tmp)
		{
			pair = tmp->content;
			if (pair)
				f(pair->value);
			tmp = tmp->next;
		}
		cnt++;
	}
}