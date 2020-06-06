//
// Created by youpaw on 06.06.2020.
//

#include "env.h"
#include "search/cc_search.h"
#include <stdlib.h>

static void	del(t_env **content)
{
	t_env *tmp;

	tmp = *content;
	if (tmp->name)
		free(tmp->name);
	if (tmp->val)
		free(tmp->val);
	free(tmp);
	*content = NULL;
}


void		env_del(void)
{
	avl_del(&g_env, (void (*)(void *)) &del);
}