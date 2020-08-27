//
// Created by youpaw on 06.06.2020.
//

#include "env.h"

int 		exec_env_insert(const char *field)
{
	return (env_insert_to(g_exec_env, field));
}
