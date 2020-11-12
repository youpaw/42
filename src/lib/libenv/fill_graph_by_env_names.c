/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_graph_by_env_names.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:05:20 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:05:23 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_graph.h"
#include "env.h"

static void		fill_graph(t_graph *graph)
{
	size_t i;
	t_list *lst;

	i = 0;
	while (i < g_env->buckets_size)
	{
		lst = g_env->buckets[i++];
		while (lst)
		{
			graph_insert(graph, ((t_hash_pair *)(lst->content))->key);
			lst = lst->next;
		}
	}
	i = 0;
	while (i < g_inter_env->buckets_size)
	{
		lst = g_inter_env->buckets[i++];
		while (lst)
		{
			graph_insert(graph, ((t_hash_pair *)(lst->content))->key);
			lst = lst->next;
		}
	}
}

void			fill_graph_by_env_names(t_graph *graph)
{
	graph_init(graph);
	fill_graph(graph);
}
