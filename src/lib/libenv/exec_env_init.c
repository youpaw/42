/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:05:10 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:05:12 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "cc_str.h"

t_hash_map *g_exec_env;

static void		cpy_pair(t_hash_pair *dst, t_hash_pair *src)
{
	dst->key = strdup(src->key);
	dst->value = src->value ? strdup(src->value) : NULL;
}

static t_list	*cpy_bucket(t_list *bucket)
{
	t_list *cpy;

	if (bucket)
	{
		cpy = lst_new(bucket->content, bucket->content_size);
		cpy_pair(cpy->content, bucket->content);
		cpy->next = cpy_bucket(bucket->next);
		return (cpy);
	}
	return (NULL);
}

void			exec_env_init(void)
{
	size_t cnt;

	cnt = 0;
	g_exec_env = hash_map_new(N_MAX_EXEC_ENV, \
	(size_t (*)(const void *)) &strhash, \
	(int (*)(const void *, const void *)) &env_cmp_pair, \
	&env_del_pair);
	while (cnt < g_env->buckets_size && cnt < g_exec_env->buckets_size)
	{
		g_exec_env->buckets[cnt] = cpy_bucket(g_env->buckets[cnt]);
		cnt++;
	}
}
