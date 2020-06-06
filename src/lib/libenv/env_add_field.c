//
// Created by youpaw on 06.06.2020.
//

#include <stdlib.h>
#include "env.h"
#include "string/cc_str.h"
#include "memory/cc_mem.h"

static t_env	*new_node(t_table_type type, char *name, char *val)
{
	t_env		*node;

	node = xmalloc(sizeof(t_env));
	node->name = name;
	node->val = val;
	node->type = type;
	return (node);
}

int 	env_add_field(t_table_type type, const char *field, int rewrite)
{
	t_env		*node;
	char		*name;
	char		*val;
	size_t		name_len;

	if (!(name_len = get_name_length(field)))
		return (1);
	name = strsub(field, 0, name_len);
	val = strdup(field + name_len + 1);
	if ((node = env_get_field(name)))
	{
		free(node->val);
		free(name);
		node->val = val;
		if (rewrite)
			node->type = type;
	}
	else
		avl_insert(g_env, avl_new_node(new_node(type, name, val)), NULL, \
    (int (*)(const void *, const void *, void *)) &env_cmp);
	return (0);
}