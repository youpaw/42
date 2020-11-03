//
// Created by Maxon Gena on 10/31/20.
//

#include "readline.h"
#include "cc_graph.h"
#include "cc_str.h"
#include "ft_select.h"

void 	handle_command_token(t_input *inp, t_predict_token *token)
{
	size_t i;
	t_graph graph;
	char **cmds;

	if (strchr(token->raw, '/'))
		handle_file_token(inp, token, X_OK);
	else
	{
		fill_complition_graph(&graph);
		cmds = graph_get_names(&graph, token->raw);
		clear_last_disp_token(token->raw, inp);
		select_choise(convert_array_2_selection(cmds), inp);
		i = 0;
		while (cmds[i])
			free(cmds[i++]);
		free(cmds);
		graph_del(&graph);
	}
}