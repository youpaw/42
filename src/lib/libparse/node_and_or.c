//
// Created by youpaw on 18.04.2020.
//

#include "parser.h"

t_ast *node_and_or(t_tokens *tokens)
{
	t_ast *node;

	node = new_ast_node(p_and_or);
	if ((node->left = node_pipeline(tokens)))
	{
		if (!get_node_token(node, tokens))
			node->right = node_list(tokens);
	}
	else
		del_ast(&node);
	return (node);
}