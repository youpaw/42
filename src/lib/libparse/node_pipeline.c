//
// Created by youpaw on 18.04.2020.
//

#include "parser.h"

t_ast *node_pipeline(t_tokens *tokens)
{
	t_ast *node;

	node = new_ast_node(p_pipeline);
	get_token_attr(node, tokens, l_bang);
	if ((node->left = node_pipe_seq(tokens)))
		return (node);
	del_ast_node(&node);
	return (NULL);
}