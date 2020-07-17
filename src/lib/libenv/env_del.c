//
// Created by youpaw on 06.06.2020.
//

#include "env.h"

void		env_del(void)
{
	hash_del(&g_env);
}