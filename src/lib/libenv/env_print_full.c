//
// Created by Azzak Omega on 8/26/20.
//

#include "env.h"
#include "cc_str.h"
#include "cc_lst.h"
#include "cc_hash_map.h"
#include "cc_mem.h"
#include "cc_sort.h"

static void 	get_names(const char **names)
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
	size_t		size;
	const char 	**names;

	size = hash_map_get_size(g_env) + hash_map_get_size(g_inter_env);
	if (size)
	{
		names = (const char **)xmalloc(sizeof(char *) * (size + 1));
		names[size] = NULL;
		get_names(names);
		quick_sort((void **) names, 0, size - 1,
				   (int (*)(const void *, const void *)) strcmp);
		print_by_names(names);
		free(names);
	}
}
