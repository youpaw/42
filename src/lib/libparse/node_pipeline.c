//
// Created by youpaw on 10/5/20.
//

#include "parser.h"

t_ast				*node_pipeline(t_tokens *tokens)
{
	t_ast *node;

	node = new_ast_node(p_pipeline);
	get_node_token(node, tokens);
	if (!(node->left = node_pipe_seq(tokens)))
		del_ast(&node);
	return (node);
}
