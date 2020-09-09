//
// Created by youpaw on 18.04.2020.
//
#include "parser.h"
#include "cc.h"

static void init_token_types(t_token_type types[1])
{
	types[0] = l_or;
}

t_ast * 			node_pipe_seq(t_tokens *tokens)
{
	t_token_type	types[1];
	t_ast			*node;
	int				error;

	node = new_ast_node(p_pipe_seq);
	if ((node->left = node_command(tokens)))
	{
		if (get_pipe_seq_attr(node, tokens))
		{
			if ((node->right = node_pipe_seq(tokens)))
				return (node);
		}
		else
			return (node);
	}
	del_ast(&node);
	return (NULL);
}