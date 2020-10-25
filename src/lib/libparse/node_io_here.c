//
// Created by Darth Butterwell on 10/17/20.
//

#include "parser.h"

t_ast				*node_io_here(t_tokens *tokens)
{
	t_ast *node;

	node = new_ast_node(p_io_here);
	if (get_node_token(node, tokens) || !(node->left = node_here_end(tokens)))
		del_ast(&node);
	return (node);
}