//
// Created by Azzak Omega on 8/26/20.
//
#include "cc_hash_map.h"
#include "cc_str.h"
#include "env.h"

int	env_insert_to(t_hash_map *hm, const char *field)
{
	t_hash_pair	pair;
	size_t		name_len;

	if (!hm || !field || !(name_len = get_valid_name_length(field)))
		return (1);
	pair.key = strsub(field, 0, name_len);
	pair.value = strdup(field + name_len + 1);
	return (hash_map_insert(hm, &pair));
}
