//
// Created by Azzak Omega on 8/27/20.
//

#include "env.h"

void		exec_env_del(void)
{
	hash_map_del(&g_exec_env);
}
