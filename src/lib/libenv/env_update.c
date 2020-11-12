//
// Created by Azzak Omega on 9/5/20.
//
#include "cc_hash_map.h"
#include "env.h"
#include "cc_str.h"

int		env_update(const char *field)
{
	t_hash_pair	pair;
	size_t		name_len;

	if (!field || !(name_len = get_valid_name_length(field)))
		return (1);
	pair.key = strsub(field, 0, name_len);
	pair.value = strdup(field + name_len + 1);
	if (hash_map_get_val(g_env, pair.key))
		return (hash_map_insert(g_env, &pair));
	return (hash_map_insert(g_inter_env, &pair));
}
