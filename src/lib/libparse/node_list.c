//
// Created by youpaw on 18.04.2020.
//

#include "parser.h"

static void init_token_types(t_token_type types[2])
{
	types[0] = l_semi;
	types[1] = l_and;
}

t_ast *node_list(t_tokens *tokens)
{
	t_token_type types[2];
	t_ast	*node;
	int		error;

	node = new_ast_node(p_list);
	if ((node->right = node_and_or(tokens)))
	{
		init_token_types(types);
		error = get_node_token(node, tokens, 2, types);
		if (!error)
			node->left = node_list(tokens);
		if (error <= 0)
			return (node);
		print_parse_error(tokens);
	}
	del_ast(&node);
	return (NULL);
}