//
// Created by youpaw on 06.06.2020.
//

#include "env.h"
#include "string/cc_str.h"

int	g_index;

static void	cpy_field(t_env *field)
{
	if (field->type == e_env  && g_index < N_MAX_EXEC_ENV)
		g_exec_env[g_index++] = nstrjoin(3, field->name, "=", field->val);
}

void		exec_env_init(void)
{
	g_index = 0;
	avl_map_infix(g_env, (void (*)(void *)) &cpy_field);
	g_exec_env[g_index] = NULL;
}
