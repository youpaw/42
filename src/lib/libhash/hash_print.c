//
// Created by Azzak Omega on 9/10/20.
//

#include "hash.h"
#include "cc_str.h"
#include "cc_num.h"
#include "cc_char.h"

static void	hash_print_bin_pair(const t_hash_pair *pair)
{
	t_hash_bin_pair *path_count;
	if (!pair)
		return ;
	path_count = pair->value;
	putnbr(path_count->count);
	putchar(' ');
	puts(path_count->path);
	putchar(' ');
	putendl(pair->key);
}

void	hash_print(void)
{
	if (!hash_map_get_size(g_hash))
		putendl("hash: hash table empty");
	else
		hash_map_iter(g_hash, (void(*)(void *))&hash_print_bin_pair);
}
