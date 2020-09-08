//
// Created by youpaw on 18.04.2020.
//

#include "parser.h"

t_ast *node_and_or(t_tokens *tokens)
{
	t_ast *node;
	int error;

	node = new_ast_node(p_and_or);
	if ((node->right = node_pipe_seq(tokens)))
	{
		if (get_node_token(node, tokens, l_and_if) \
 || get_node_token(node, tokens, l_or_if))
		{
			if ((node->right = node_and_or(tokens)))
				return (node);
		}
		else
			return (node);
	}
	del_ast_node(&node);
	return (NULL);
}