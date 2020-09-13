//
// Created by Darth Butterwell on 9/9/20.
//

#include "error.h"
#include "lexer.h"
#include "env.h"

void 	print_parse_error(t_tokens *tokens)
{
	const char *args[1];

	g_exit_code = E_UNEXPTOK;
	args[0] = tokens->tokens[tokens->index]->raw;
	error_print(E_UNEXPTOK, args);
}