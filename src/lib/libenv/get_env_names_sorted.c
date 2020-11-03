//
// Created by Maxon Gena on 11/3/20.
//

#include "env.h"
#include "cc_str.h"
#include "cc_lst.h"
#include "cc_hash_map.h"
#include "cc_mem.h"
#include "cc_sort.h"

static void 	get_names(char **names)
{
	size_t i;
	t_list *lst;

	i = 0;
	while (i < g_env->buckets_size)
	{
		lst = g_env->buckets[i++];
		while (lst)
		{
			*names++ = strdup(((t_hash_pair *)(lst->content))->key);
			lst = lst->next;
		}
	}
	i = 0;
	while (i < g_inter_env->buckets_size)
	{
		lst = g_inter_env->buckets[i++];
		while (lst)
		{
			*names++ = strdup(((t_hash_pair *)(lst->content))->key);
			lst = lst->next;
		}
	}
}

char	**get_all_env_names_sorted(void)
{
	size_t		size;
	char 	**names;

	size = hash_map_get_size(g_env) + hash_map_get_size(g_inter_env);
	if (size)
	{
		names = xmalloc(sizeof(char *) * (size + 1));
		names[size] = NULL;
		get_names(names);
		quick_sort((void **) names, 0, (int)size - 1,
				   (int (*)(const void *, const void *)) strcmp);
		return (names);
	}
	return (NULL);
}
