//
// Created by youpaw on 18.04.2020.
//

#include "parser.h"

t_ast		*node_io_redirect(t_tokens *tokens)
{
	t_ast *node;

	node = new_ast_node(p_io_redirect);
	get_node_token(node, tokens);
	if (!(node->left = node_io_file(tokens)))
		del_ast(&node);
	return (node);
}
