//
// Created by Azzak Omega on 9/5/20.
//
#include "cc_hash_map.h"
#include "env.h"
#include "cc_str.h"

int 		env_export(const char *field)
{
	t_hash_pair	pair;
	size_t		name_len;
	char 		*value;

	if (!field || !(name_len = get_valid_name_length_no_check(field)) ||
			(field[name_len] && field[name_len] != '='))
		return (1);
	pair.key = strsub(field, 0, name_len);
	if (!field[name_len])
	{
		if ((value = hash_map_get_val(g_inter_env, pair.key)))
			pair.value = strdup(value);
		else
			pair.value = strnew(0);
	}
	else
		pair.value = strdup(field + name_len + 1);
	hash_map_del_one(g_inter_env, pair.key);
	return (hash_map_insert(g_env, &pair));
}
