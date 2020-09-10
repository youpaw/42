//
// Created by youpaw on 18.04.2020.
//

#include "parser.h"

int			node_and_or(t_tokens *tokens, t_ast **root)
{
	int		error;

	*root = new_ast_node(p_and_or);
	if (!(error = node_pipe_seq(tokens, &(*root)->left)))
	{
		if ((error = get_node_token(*root, tokens)) > 0)
			print_parse_error(tokens);
		else if (error < 0 || !node_and_or(tokens, &(*root)->right))
			return (0);
	}
	return (error);
}