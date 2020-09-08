//
// Created by youpaw on 18.04.2020.
//

#include "parser.h"

t_ast *node_list(t_tokens *tokens)
{
	int		error;
	t_ast	*node;

	node = new_ast_node(p_list);
	if ((node->right = node_and_or(tokens)))
	{
		if (tokens->index < tokens->size)
		{
			error = get_node_token(node, tokens, 2, l_semi, l_and);
			if (error == 1)
				node->left = node_list(tokens);
		}
		return (node);
	}
	del_ast_node(&node);
	return (NULL);
}