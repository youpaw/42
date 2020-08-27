//
// Created by Azzak Omega on 8/26/20.
//

#include "env.h"
#include "cc_str.h"
#include "cc_lst.h"
#include "cc_hash_map.h"
#include "cc_mem.h"

static size_t 	get_names(const char **names)
{
	size_t i;
	t_list *lst;

	i = 0;
	while (i < g_env->buckets_size)
	{
		lst = g_env->buckets[i++];
		while (lst)
		{
			*names++ = ((t_hash_pair *)(lst->content))->key;
			lst = lst->next;
		}
	}
	i = 0;
	while (i < g_inter_env->buckets_size)
	{
		lst = g_inter_env->buckets[i++];
		while (lst)
		{
			*names++ = ((t_hash_pair *)(lst->content))->key;
			lst = lst->next;
		}
	}
}

static void	print_by_names(const char **names)
{
	t_hash_pair pair;

	if (!names)
		return ;
	while ((pair.key = (void *)*names++))
	{
		if (!(pair.value = hash_map_get_val(g_env, pair.key)))
			pair.value = hash_map_get_val(g_inter_env, pair.key);
		env_print_pair(&pair);
	}
}

void		env_print_full(void)
{
	size_t		size;
	char 	**names;

	size = hash_map_get_size(g_env) + hash_map_get_size(g_inter_env);
	names = (char **)xmalloc(size + 1);
	names[size] = NULL;
	get_names(names);
	//sort names
	print_by_names(names);
	free(names);
}
