/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_names_sorted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:05:25 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:05:28 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "cc_str.h"
#include "cc_lst.h"
#include "cc_hash_map.h"
#include "cc_mem.h"
#include "cc_sort.h"

static void		get_names(const char **names)
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

const char		**get_all_env_names_sorted(void)
{
	size_t		size;
	const char	**names;

	size = hash_map_get_size(g_env) + hash_map_get_size(g_inter_env);
	if (size)
	{
		names = xmalloc(sizeof(char *) * (size + 1));
		names[size] = NULL;
		get_names(names);
		quick_sort((void **)names, 0, (int)size - 1,
				(int (*)(const void *, const void *)) strcmp);
		return (names);
	}
	return (NULL);
}
