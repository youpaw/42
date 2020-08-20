/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 19:08:02 by azomega           #+#    #+#             */
/*   Updated: 2020/08/19 19:08:06 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_graph.h"
#include "list/cc_lst.h"

void	graph_del(t_graph *graph)
{
	if (graph)
	{
		lst_del(&(graph->childs), (void (*)(void *))graph_del);
		graph->childs = NULL;
	}
}
