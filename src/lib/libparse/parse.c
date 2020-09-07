//
// Created by youpaw on 18.04.2020.
//

#include "parser.h"
#include "cc.h"

t_ast				*parse(t_tokens *tokens)
{
	t_ast *ast;

	tokens->index = 0;
	ast = node_complete_cmd(tokens);
	if (tokens->index < tokens->size)
		fdputs("Parser error", 2);
	return (ast);
}