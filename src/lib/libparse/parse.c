//
// Created by youpaw on 18.04.2020.
//

#include "parser.h"
#include "error.h"
#include "env.h"

t_ast				*parse(t_tokens *tokens)
{
	const char	*args[1];
	t_ast		*ast;

	ast = node_complete_cmd(tokens);
	if (tokens->index < tokens->size)
	{
		del_ast(&ast);
		tokens->error = E_UNEXPTOK;
		g_exit_code = E_UNEXPTOK;
		args[0] = tokens->tokens[tokens->index]->type == l_newline ? \
			token_type_to_string(l_newline) : \
			tokens->tokens[tokens->index]->raw;
		error_print(E_UNEXPTOK, args);
	}
	return (ast);
}
