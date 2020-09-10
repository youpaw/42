//
// Created by youpaw on 18.04.2020.
//

#include "parser.h"
#include "cc.h"

t_ast				*parse(t_tokens *tokens)
{
	t_ast	*ast;
	int 	error;

	tokens->index = 0;
	error = node_complete_cmd(tokens, &ast);
	if (tokens->index < tokens->size)
		fdputs("Parser error", 2);
	return (ast);
}