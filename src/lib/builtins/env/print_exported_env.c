//
// Created by Azzak Omega on 9/16/20.
//

#include "env.h"
#include "cc_str.h"
#include "cc_sort.h"
#include "cc_mem.h"

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
}

static void	export_print_pair(const t_hash_pair *pair)
{
	puts("export ");
	puts(pair->key);
	if (pair->value)
	{
		puts("=");
		puts(pair->value);
	}
	puts("\n");
}

int	print_exported_env(void)
{
	size_t		size;
	const char 	**names;
	const char 	**head;
	t_hash_pair pair;

	size = hash_map_get_size(g_env);
	if (size)
	{
		names = (const char **)xmalloc(sizeof(char *) * (size + 1));
		head = names;
		names[size] = NULL;
		get_names(names);
		quick_sort((void **) names, 0, size - 1,
				   (int (*)(const void *, const void *)) strcmp);
		while ((pair.key = (void *)*names++))
		{
			pair.value = hash_map_get_val(g_env, pair.key);
			export_print_pair(&pair);
		}
		free(head);
	}
	return (0);
}
