//
// Created by Azzak Omega on 8/27/20.
//

#include "env.h"
#include "cc_hash_map.h"

const char	*env_get_value(const char *key)
{
	const char *value;

	if (!(value = hash_map_get_val(g_env, key)))
		return (hash_map_get_val(g_inter_env, key));
	return (value);
}
