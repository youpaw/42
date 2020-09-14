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
		if (!get_node_token(node, tokens))
			node->right = node_pipe_seq(tokens);
	}
	else
		del_ast(&node);
	return (node);
}
