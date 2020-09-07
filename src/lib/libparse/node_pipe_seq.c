//
// Created by youpaw on 18.04.2020.
//
#include "parser.h"
#include "cc.h"

static int 			get_pipe_seq_attr(t_ast *node, t_tokens *tokens)
{
	t_token *token;

	token = tokens->tokens[tokens->index];
	if (!strcmp(token->raw, "|"))
	{
		node->token = token;
		tokens->index++;
		return (1);
	}
	return (0);
}

t_ast * 			node_pipe_seq(t_tokens *tokens)
{
	t_ast *node;

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
	del_ast_node(&node);
	return (NULL);
}