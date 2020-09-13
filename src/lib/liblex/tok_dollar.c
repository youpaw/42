//
// Created by Darth Butterwell on 8/7/20.
//
#include "lexer.h"

int 	tok_dollar(t_lexer *lexer)
{
	t_brace	brace;
	int		error;

	error = E_OK;
	if (get_brace(lexer->raw + lexer->index, &brace) > 0)
		error = match_brace(lexer, brace);
	lexer->index--;
	vec_rm_last(lexer->states);
	return (error);
}
