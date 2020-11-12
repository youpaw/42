//
// Created by youpaw on 9/24/20.
//

#include "lexer.h"
#include "cc_str.h"

int		expand_token(t_token *token)
{
	int			error;
	t_lexer		lexer;

	error = lex_raw(&lexer, token->raw, l_exp);
	if (!error)
	{
		free(token->raw);
		token->raw = strdup(lexer.raw);
	}
	lex_del(&lexer);
	return (error);
}
