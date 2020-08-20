/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cc_graph.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 19:07:43 by azomega           #+#    #+#             */
/*   Updated: 2020/08/19 19:07:46 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CC_GRAPH_H
# define CC_GRAPH_H

# include "list/cc_lst.h"

typedef struct	s_graph
{
	char		symbol;
	size_t		index;
	t_list		*childs;
}				t_graph;

t_graph			*graph_new(char symbol, size_t index);
void			graph_init(t_graph *graph);
void			graph_del(t_graph *graph);
int				graph_cmp(const t_graph *lhs, const t_graph *rhs);
void			graph_insert(t_graph *graph, const char *word);
char			**graph_get_suffixes(const t_graph *graph);
char			**graph_get_names(const t_graph *graph, const char *word);

#endif
