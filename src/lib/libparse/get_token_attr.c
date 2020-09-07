//
// Created by youpaw on 19.04.2020.
//

#include "parser.h"

int get_token_attr(t_ast *node, t_tokens *tokens, t_token_type type)
{
	t_token *token;

	if (tokens->index >= tokens->size)
		return (0);
	token = tokens->tokens[tokens->index];
	if (token->type == type)
	{
		node->token = token;
		tokens->index++;
		return (1);
	}
	return (0);
}