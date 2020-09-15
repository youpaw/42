//
// Created by youpaw on 18.04.2020.
//

#include "parser.h"

t_ast *node_simple_cmd(t_tokens *tokens)
{
	t_ast *node;

	node = new_ast_node(p_simple_cmd);
	node->left = node_cmd_prefix(tokens);
	if (!get_node_token(node, tokens))
		node->right = node_cmd_suffix(tokens);
	else if(!node->left)
		del_ast(&node);
	return (node);
}
