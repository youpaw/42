//
// Created by youpaw on 02.06.2020.
//

#include "env.h"
#include "cc_str.h"
#include "cc_hash_map.h"

int			g_exit_code = 0;
t_hash_map	*g_env;
t_hash_map	*g_inter_env;

static void	init_env_from_str(t_hash_map *map, const char **env)
{
	if (map && env)
		while (*env)
			env_insert_to(map, *env++);
}

void		env_init(const char **env)
{
	g_env = hash_map_new(N_MAX_ENV, (size_t (*)(const void *)) &strhash, \
		(int (*)(const void *, const void *)) &env_cmp_pair, &env_del_pair);
	init_env_from_str(g_env, env);
	g_inter_env = hash_map_new(N_MAX_ENV, (size_t (*)(const void *)) &strhash, \
		(int (*)(const void *, const void *)) &env_cmp_pair, &env_del_pair);
}
