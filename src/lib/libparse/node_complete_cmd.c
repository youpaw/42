//
// Created by youpaw on 18.04.2020.
//

#include "parser.h"

t_ast	*node_complete_cmd(t_tokens *tokens)
{
	t_ast *node;

	node = new_ast_node(p_cmpl_cmd);
	if ((node->left = node_list(tokens)))
		while (!get_node_token(node, tokens))
			;
	else
		del_ast(&node);
	return (node);
}
