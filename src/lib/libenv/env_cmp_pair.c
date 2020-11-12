//
// Created by Azzak Omega on 8/27/20.
//

#include "env.h"
#include "cc_str.h"

int		env_cmp_pair(const t_hash_pair *lhs, const t_hash_pair *rhs)
{
	return (strcmp(lhs->key, rhs->key));
}
