//
// Created by Darth Butterwell on 9/13/20.
//

#include "lexer.h"

void		lex_del(t_lexer *lexer)
{
	if (lexer->slices)
		vec_del(&lexer->slices);
	if (lexer->tokens)
		vec_del(&lexer->tokens);
	if (lexer->raw)
		free(lexer->raw);
}
