//
// Created by Darth Butterwell on 8/7/20.
//
#include "lexer.h"

int 	tok_single_quote(t_lexer *lexer)
{
	while (lexer->raw[lexer->index] != '\'' && lexer->index < lexer->size)
		lexer->index++;
	if (lexer->index == lexer->size)
		return (E_INCOMPLETE_INPUT);
	vec_rm_last(lexer->states);
	return (0);
}