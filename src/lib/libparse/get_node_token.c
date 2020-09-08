//
// Created by youpaw on 19.04.2020.
//

#include <stdarg.h>
#include "parser.h"

int get_node_token(t_ast *node, t_tokens *tokens, int n_types, ...)
{
	va_list	argptr;
	t_token *token;

	if (tokens->index >= tokens->size)
		return (-1);
	token = tokens->tokens[tokens->index];
	va_start(argptr, n_types);
	while (n_types--)
	{
		if (token->type == va_arg(argptr, t_token_type))
		{
			node->token = token;
			tokens->index++;
			va_end(argptr);
			return (1);
		}
	}
	va_end(argptr);
	return (0);
}