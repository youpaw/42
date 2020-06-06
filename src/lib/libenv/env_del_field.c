//
// Created by youpaw on 06.06.2020.
//

#include <stdlib.h>
#include "env.h"

void	env_del_field(const char *name)
{
	t_env *field;

	field = avl_pop(&g_env, name, NULL, \
	(int (*)(const void *, const void *, void *)) env_cmp);
	if (field)
	{
		free(field->val);
		free((field->name));
		free(field);
	}
}
