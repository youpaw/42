//
// Created by youpaw on 6/21/20.
//

#include "cc_hash_map.h"

void 			hash_map_del(t_hash_table **table)
{
	size_t cnt;

	cnt = 0;
	while (cnt < (*table)->size)
		lst_del(&((*table)->buckets[cnt++]), (void (*)(void *)) (*table)->del);
	free((*table)->buckets);
	free(*table);
	*table = NULL;
}