//
// Created by Azzak Omega on 11/11/20.
//
#include "env.h"

const char	*exec_env_get_value(const char *key)
{
	return (hash_map_get_val(g_exec_env, key));
}
