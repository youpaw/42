//
// Created by youpaw on 18.04.2020.
//

#include "parser.h"

t_ast		*node_io_file(t_tokens *tokens)
{
	t_ast *node;

	node = new_ast_node(p_io_file);
	if (get_node_token(node, tokens) || !(node->left = node_filename(tokens)))
		del_ast(&node);
	return (node);
}
