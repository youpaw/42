//
// Created by youpaw on 18.04.2020.
//

#include "parser.h"

t_ast 		*node_list(t_tokens *tokens)
{
	t_ast *node;

	node = new_ast_node(p_list);
	if ((node->left = node_and_or(tokens)))
	{
		tokens->error = get_node_token(node, tokens);
		if (!tokens->error && tokens->index < tokens->size)
			node->right = node_list(tokens);
		else if (tokens->error == E_NULL_INPUT)
			tokens->error = 0;
	}
	if (tokens->error)
		del_ast(&node);
	return (node);
}
