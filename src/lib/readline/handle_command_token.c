//
// Created by Maxon Gena on 10/31/20.
//

#include "readline.h"
#include "cc_graph.h"
#include "cc_str.h"
#include "ft_select.h"

void 	handle_command_token(t_inp *inp, t_prdct_tkn *token)
{
	size_t i;
	t_graph graph;
	char **cmds;

	if (strchr(token->raw, '/'))
		handle_file_token(inp, token, 1);
	else
	{
		fill_complition_graph(&graph);
		cmds = graph_get_names(&graph, token->raw);
		if (!cmds)
		{
			handle_symbol_key(inp, " \0\0\0");
			graph_del(&graph);
			return ;
		}
		select_choise(convert_array_2_selection(cmds), inp, token->raw);
		i = 0;
		while (cmds[i])
			free(cmds[i++]);
		free(cmds);
		graph_del(&graph);
	}
}