//
// Created by youpaw on 06.06.2020.
//

#include "env.h"

void		env_print_global(void)
{
	hash_map_iter(g_env, (void(*)(void *))&env_print_pair);
}
