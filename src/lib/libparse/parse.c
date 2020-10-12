//
// Created by youpaw on 18.04.2020.
//

#include "parser.h"

t_ast				*parse(t_tokens *tokens)
{
	t_ast	*ast;

	ast = node_complete_cmd(tokens);
	if (tokens->index < tokens->size)
	{
		del_ast(&ast);
		tokens->error = E_UNEXPTOK;
		print_parse_error(tokens);
	}
	return (ast);
}
