//
// Created by youpaw on 18.04.2020.
//

#include "parser.h"
#include "cc.h"

static int get_sep_op_attr(t_ast *node, t_tokens *tokens)
{
	t_token token;

	token = tokens->tokens[tokens->index];
	if (str_equals(token.raw, "&") || str_equals(token.raw, ";"))
	{
		node->attr = token;
		tokens->index++;
		return (1);
	}
	return (0);
}

t_ast *node_list(t_tokens *tokens)
{
	t_ast *node;

	node = new_ast_node(p_list);
	if ((node->left = node_and_or(tokens)))
	{
		if (get_sep_op_attr(node, tokens))
		{
			if ((node->right = node_list(tokens)))
				return (node);
		}
		else
			return (node);
	}
	del_ast_node(&node);
	return (NULL);
}