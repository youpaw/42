/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 19:15:01 by azomega           #+#    #+#             */
/*   Updated: 2020/08/19 19:15:02 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_graph.h"
#include <stdlib.h>

t_graph	*graph_new(char symbol, size_t index)
{
	t_graph	*graph;

	if (!(graph = (t_graph *)malloc(sizeof(t_graph))))
		return (NULL);
	graph->symbol = symbol;
	graph->index = index;
	graph->childs = NULL;
	return (graph);
}
