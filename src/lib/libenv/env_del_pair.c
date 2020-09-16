//
// Created by youpaw on 6/24/20.
//

#include "env.h"

void 		env_del_pair(t_hash_pair *pair)
{
	free(pair->key);
	if (pair->value)
		free(pair->value);
}
