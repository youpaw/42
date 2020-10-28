//
// Created by Azzak Omega on 8/29/20.
//

#include "cc_hash_map.h"
#include "cc_str.h"
#include "cc_char.h"
#include "alias.h"

static int is_char_valid(char c)
{
	return (!(isspace(c) || c == '=') || c == '/'); // is it? this need proof
}

size_t get_valid_alias_name_len(const char *name)
{
	size_t index;

	index = 0;
	if (name[index] == '-')
		return (0);
	while (is_char_valid(name[index]))
		index++;
	if (name[index] != '=')
		return (0);
	return (index);
}

int 		alias_add(const char *field)
{
	t_hash_pair	pair;
	size_t		name_len;

	if (!field || !(name_len = get_valid_alias_name_len(field)))
		return (1);
	pair.key = strsub(field, 0, name_len);
	pair.value = strdup(field + name_len + 1);
	return (hash_map_insert(g_aliases, &pair));
}
