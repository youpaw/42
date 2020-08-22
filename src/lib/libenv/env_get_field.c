//
// Created by youpaw on 06.06.2020.
//

#include <zconf.h>
#include "env.h"

t_env		*env_get_field(const char *name)
{
	return (hash_map_get_val(g_env, name));
}
