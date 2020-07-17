//
// Created by youpaw on 06.06.2020.
//

#include "env.h"
#include "string/cc_str.h"
#include "char/cc_char.h"
#include "memory/cc_mem.h"

static t_env 	*new_field(char *val)
{
	t_env		*field;

	field = xmalloc(sizeof(t_env));
	field->val = val;
	field->type = e_env;
	return (field);
}

int 		exec_env_add(const char *field)
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
	pair.value = new_field(val);
	hash_insert(g_exec_env, &pair);
	return (0);
}
