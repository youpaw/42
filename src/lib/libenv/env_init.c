//
// Created by youpaw on 02.06.2020.
//

#include "env.h"
#include "string/cc_str.h"

int	g_exit_code = 0;
t_hash_table *g_env;

void	env_init(const char **env)
{
	int cnt;

	cnt = 0;
	g_env = hash_new(N_MAX_ENV, \
    (size_t (*)(const void *)) &strhash, \
	(int (*)(const void *, const void *)) &strcmp, \
	&env_del_pair);
	while (env[cnt])
		env_add_field(e_env, env[cnt++]);
}
