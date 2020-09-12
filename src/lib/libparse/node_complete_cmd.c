//
// Created by youpaw on 18.04.2020.
//

#include "parser.h"

t_ast	*node_complete_cmd(t_tokens *tokens)
{
	t_ast *node;

	node = new_ast_node(p_cmpl_cmd);
	node->left = node_list(tokens);
	if (tokens->error)
		del_ast(&node);
	return (node);
}