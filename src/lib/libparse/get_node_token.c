//
// Created by youpaw on 19.04.2020.
//

#include "parser.h"

static void init_token_types(t_token_type types[2])
{
	static const t_token_type token_type_map[N_NODE_TYPES][N_MAX_TOKEN_TYPES] = {
			{-1}, {l_and, l_semi, -1}, {l_and_if, l_or_if, -1}, {l_or, -1},
			{l_command_name, -1}, {l_assignment_word, -1}, {l_word, -1},
			{l_io_number, -1}, {l_less, l_less_and, l_great}
	}
}

int get_node_token(t_ast *node, t_tokens *tokens, int n_types, const t_token_type types[])
{
	t_token *token;

	if (tokens->index >= tokens->size)
		return (-1);
	token = tokens->tokens[tokens->index];
	while (n_types--)
	{
		if (token->type == types[n_types])
		{
			node->token = token;
			tokens->index++;
			return (0);
		}
	}
	return (1);
}