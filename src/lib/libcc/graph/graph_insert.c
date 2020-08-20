/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 19:15:16 by azomega           #+#    #+#             */
/*   Updated: 2020/08/19 19:15:19 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_graph.h"

void			graph_insert(t_graph *graph, const char *word)
{
	t_list	*found;
	t_graph	new;

	if (!word)
		return ;
	new.symbol = *word;
	new.index = graph->index + 1;
	new.childs = NULL;
	found = lst_find(graph->childs, (int (*)(const void *,
			const void *))graph_cmp, &new);
	if (!found)
	{
		lst_add_sort(&(graph->childs), lst_new(&new, sizeof(new)), NULL,
					(int (*)(const void *, const void *, void *))graph_cmp);
		found = lst_find(graph->childs,
				(int (*)(const void *, const void *))graph_cmp, &new);
	}
	if (!(*word))
		return ;
	graph_insert(found->content, ++word);
}
