//
// Created by youpaw on 18.04.2020.
//

#include "parser.h"

static void init_token_types(t_token_type types[2])
{
	types[0] = l_and_if;
	types[1] = l_or_if;
}

t_ast *node_and_or(t_tokens *tokens)
{
	t_token_type types[2];
	t_ast *node;
	int error;

	node = new_ast_node(p_and_or);
	if ((node->right = node_pipe_seq(tokens)))
	{
		init_token_types(types);
		error = get_node_token(node, tokens, 2, types);
		if (!error)
			node->right = node_and_or(tokens);
		if (error <= 0)
			return (node);
		print_parse_error(tokens);
	}
	del_ast(&node);
	return (NULL);
}