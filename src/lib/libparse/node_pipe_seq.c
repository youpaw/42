//
// Created by youpaw on 18.04.2020.
//
#include "parser.h"

t_ast *node_pipe_seq(t_tokens *tokens)
{
	t_ast *node;

	node = new_ast_node(p_pipe_seq);
	if ((node->left = node_simple_cmd(tokens)))
	{
		tokens->error = get_node_token(node, tokens);
		if (!tokens->error)
		{
			if (tokens->index < tokens->size)
				node->right = node_pipe_seq(tokens);
			else
				tokens->error = E_NULL_INPUT;
		}
		else if (tokens->error == E_NULL_INPUT)
			tokens->error = 0;
	}
	if (tokens->error)
		del_ast(&node);
	return (node);
}
