//
// Created by youpaw on 06.06.2020.
//

#include <stdlib.h>
#include "env.h"
#include "string/cc_str.h"
#include "memory/cc_mem.h"
#include "char/cc_char.h"

static t_env 	*new_field(t_table_type type, char *val)
{
	t_env		*field;

	field = xmalloc(sizeof(t_env));
	field->val = val;
	field->type = type;
	return (field);
}

int 	env_add_field(t_table_type type, const char *field)
{
	t_hash_pair pair;
	char		*name;
	char		*val;
	size_t		name_len;

	name_len = get_name_length(field);
	if (!name_len || isdigit(field[0]) || field[name_len] != '=')
		return (1);
	name = strsub(field, 0, name_len);
	val = strdup(field + name_len + 1);
	pair.key = name;
	pair.value = new_field(type, val);
	hash_insert(g_env, &pair);
	return (0);
}