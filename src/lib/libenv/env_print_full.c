//
// Created by Azzak Omega on 8/26/20.
//

#include "env.h"
#include "cc_lst.h"
#include "cc_str.h"
#include "cc_hash_map.h"

static void	print_by_names(const char **names)
{
	t_hash_pair pair;

	if (names)
		while ((pair.key = (void *)*names++))
		{
			if (!(pair.value = hash_map_get_val(g_env, pair.key)))
				pair.value = hash_map_get_val(g_inter_env, pair.key);
			env_print_pair(&pair);
		}
}

void		env_print_full(void)
{
	const char	**names;

	if ((names = get_all_env_names_sorted()))
	{
		print_by_names((const char **)names);
		free(names);
	}
}
