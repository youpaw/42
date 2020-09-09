//
// Created by youpaw on 18.04.2020.
//

#include "parser.h"

static void init_token_types(t_token_type types[1])
{
	types[0] = l_command_name;
}

t_ast * 			node_simple_cmd(t_tokens *tokens)
{
	t_ast *node;
	t_token_type types[1];

	node = new_ast_node(p_simple_cmd);
	node->left = node_cmd_prefix(tokens);
	init_token_types(types);
	if (!get_node_token(node, tokens, 1, types))
	{
		del_ast(&node);
		return (NULL);
	}
	node->right = node_cmd_suffix(tokens);
	return (node);
}