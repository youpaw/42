//
// Created by youpaw on 06.06.2020.
//

#include <zconf.h>
#include "env.h"

t_env		*env_get_field(const char *name)
{
	t_avl *node;

	node = avl_get_node(g_env, name, NULL, \
	(int (*)(const void *, const void *, void *)) &env_cmp);
	if (node)
		return (node->content);
	return (NULL);
}
