//
// Created by youpaw on 18.04.2020.
//

#include "parser.h"

t_ast *node_command(t_tokens *tokens)
{
	t_ast *node;

	node = new_ast_node(p_command);
	if ((node->left = node_simple_cmd(tokens)))
		return (node);
	del_ast(&node);
	return (NULL);
}
