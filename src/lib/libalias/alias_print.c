/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:13:11 by mgena             #+#    #+#             */
/*   Updated: 2020/11/15 19:19:19 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alias.h"
#include "cc_str.h"
#include "cc_lst.h"
#include "cc_hash_map.h"
#include "cc_mem.h"
#include "cc_sort.h"

static void		get_names(const char **names)
{
	size_t	i;
	t_list	*lst;

	i = 0;
	while (i < g_aliases->buckets_size)
	{
		lst = g_aliases->buckets[i++];
		while (lst)
		{
			*names++ = ((t_hash_pair *)(lst->content))->key;
			lst = lst->next;
		}
	}
}

static void		alias_print_pair(const t_hash_pair *pair)
{
	if (!pair)
		return ;
	puts("alias ");
	puts(pair->key);
	puts("='");
	puts(pair->value);
	putendl("'");
}

static void		print_by_names(const char **names)
{
	t_hash_pair	pair;

	if (names)
		while ((pair.key = (void *)*names++))
		{
			pair.value = hash_map_get_val(g_aliases, pair.key);
			alias_print_pair(&pair);
		}
}

void			alias_print(void)
{
	size_t		size;
	const char	**names;

	size = hash_map_get_size(g_aliases);
	if (size)
	{
		names = (const char **)xmalloc(sizeof(char *) * (size + 1));
		names[size] = NULL;
		get_names(names);
		quick_sort((void **)names, 0, size - 1,
				(int (*)(const void *, const void *))strcmp);
		print_by_names(names);
		free(names);
	}
}
