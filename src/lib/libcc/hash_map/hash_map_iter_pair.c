//
// Created by youpaw on 6/24/20.
//

#include "cc_hash_map.h"

void 			hash_map_iter_pair(t_hash_table *table, void (*f)(const t_hash_pair *pair))
{
	t_list *tmp;
	size_t cnt;

	cnt = 0;
	while (cnt < table->size)
	{
		tmp = table->buckets[cnt];
		while (tmp)
		{
			f(tmp->content);
			tmp = tmp->next;
		}
		cnt++;
	}
}