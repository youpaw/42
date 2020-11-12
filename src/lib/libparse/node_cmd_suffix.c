//
// Created by youpaw on 18.04.2020.
//

#include "parser.h"

t_ast			*node_cmd_suffix(t_tokens *tokens)
{
	t_ast *node;

	node = new_ast_node(p_cmd_suff);
	if ((node->left = node_io_redirect(tokens)) || \
		!get_node_token(node, tokens))
		node->right = node_cmd_suffix(tokens);
	else
		del_ast(&node);
	return (node);
}
