//
// Created by youpaw on 18.04.2020.
//

#include "parser.h"

t_ast * 			node_cmd_prefix(t_tokens *tokens)
{
	t_ast *node;

	node = new_ast_node(p_cmd_pref);
	if ((node->left = node_io_redirect(tokens)))
	{
		node->right = node_cmd_prefix(tokens);
		return (node);
	}
	if (get_token_attr(node, tokens, l_assignment_word))
	{
		node->right = node_cmd_prefix(tokens);
		return (node);
	}
	del_ast_node(&node);
	return (NULL);
}