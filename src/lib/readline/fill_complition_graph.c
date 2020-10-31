//
// Created by Halfhand Lorrine on 10/31/20.
//

#include "cc_graph.h"
#include "readline.h"


static void		fill_builtins(t_graph *graph)
{
	static const char *builtins_names[N_BUILTINS] = {
			"exit", "set", "unset", "cd", "export", "hash", "echo",\
			"alias", "unalias"};
	int i;

	i = 0;
	while (i < N_BUILTINS)
	{
		graph_insert(graph, builtins_names[i]);
		i++;
	}
}

void	fill_complition_graph(t_graph *graph)
{
	graph_init(graph);
	fill_builtins(graph);

	graph_insert(graph, "abc");
	graph_insert(graph, "af");
	graph_insert(graph, "abcd");
}