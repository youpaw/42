//
// Created by Darth Butterwell on 9/13/20.
//

#include "lexer.h"

void 		lex_del(t_lexer *lexer)
{
	if (lexer->states)
		vec_del(&lexer->states);
	if (lexer->tokens)
		vec_del(&lexer->tokens);
	if (lexer->raw)
		free(lexer->raw);
}