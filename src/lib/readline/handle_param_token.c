//
// Created by Maxon Gena on 11/3/20.
//

#include "readline.h"
#include "ft_select.h"
#include "env.h"

void 	handle_param_token(t_inp *inp, t_prdct_tkn *token)
{
	size_t i;
	t_graph graph;
	char **params;

	fill_graph_by_env_names(&graph);
	params = graph_get_names(&graph, token->raw);
	if (params)
	{
		clear_last_disp_token(token->raw, inp);
		select_choise(convert_array_2_selection(params), inp, token->raw);
		i = 0;
		while (params[i])
			free(params[i++]);
		free(params);
		graph_del(&graph);
	}
}