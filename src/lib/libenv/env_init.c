//
// Created by youpaw on 02.06.2020.
//

#include "env.h"

void	env_init(const char **env)
{
	int cnt;

	cnt = 0;
	while (env[cnt])
		env_add_field(e_env, env[cnt++], 0);
}