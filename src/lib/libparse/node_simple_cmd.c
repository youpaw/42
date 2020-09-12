//
// Created by youpaw on 18.04.2020.
//

#include "parser.h"

t_ast *node_simple_cmd(t_tokens *tokens)
{
	t_ast *node;

	node = new_ast_node(p_simple_cmd);
	node->left = node_cmd_prefix(tokens);
	tokens->error = get_node_token(node, tokens);
	if (!tokens->error)
	{
		node->right = node_cmd_suffix(tokens);
		tokens->error = 0;
	}
	else if (node->left)
		tokens->error = 0;
	if (tokens->error)
		del_ast(&node);
	return (node);
}
