//
// Created by youpaw on 19.04.2020.
//

#include "parser.h"

int get_node_token(t_ast *node, t_tokens *tokens)
{
	static const t_token_type token_type_map[N_NODE_TYPES][N_MAX_TOKEN_TYPES] = {
			{-1}, {l_and, l_semi, -1}, {l_and_if, l_or_if, -1}, {l_or, -1},
			{l_command_name, -1}, {l_assignment_word, -1}, {l_word, -1},
			{l_io_number, -1},
			{l_less, l_less_and, l_great, l_great_and, l_double_great -1},
			{l_word, -1}
	};
	t_token *token;
	int 	index;

	if (tokens->index >= tokens->size)
		return (-1);
	token = tokens->tokens[tokens->index];
	index = 0;
	while ((int)token_type_map[node->type][index] >= 0)
	{
		if (token->type == token_type_map[node->type][index])
		{
			node->token = token;
			tokens->index++;
			return (0);
		}
		index++;
	}
	return (1);
}