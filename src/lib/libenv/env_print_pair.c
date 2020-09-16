//
// Created by Azzak Omega on 8/27/20.
//

#include "env.h"
#include "cc_str.h"

void	env_print_pair(const t_hash_pair *pair)
{
	if (!pair || !pair->value)
		return ;
	puts(pair->key);
	puts("=");
	putendl(pair->value);
}

