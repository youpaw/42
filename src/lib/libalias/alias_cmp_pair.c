//
// Created by Azzak Omega on 8/29/20.
//

#include "cc_hash_map.h"
#include "cc_str.h"

int 		alias_cmp_pair(const t_hash_pair *lhs, const t_hash_pair *rhs)
{
	return (strcmp(lhs->key, rhs->key));
}
