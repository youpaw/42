//
// Created by youpaw on 18.04.2020.
//

#include "parser.h"
#include "cc.h"

t_ast 		*node_io_file(t_tokens *tokens)
{
	t_ast *node;

	node = new_ast_node(p_io_file);
	tokens->error = get_node_token(node, tokens);
	if (!tokens->error)
		node->left = node_filename(tokens);
	if (tokens->error)
		del_ast(&node);
	return (node);
}