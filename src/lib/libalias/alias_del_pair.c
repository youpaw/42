//
// Created by Azzak Omega on 8/29/20.
//

#include "cc_hash_map.h"

void 		alias_del_pair(t_hash_pair *pair)
{
	free(pair->key);
	free(pair->value);
}
