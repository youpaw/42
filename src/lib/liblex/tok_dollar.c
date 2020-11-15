//
// Created by Darth Butterwell on 8/7/20.
//
#include "lexer.h"

int	tok_dollar(t_lexer *lexer)
{
	t_brace	brace;
	int		error;

	error = 0;
	if (get_brace(lexer->raw + lexer->index, &brace) > 0)
		error = match_brace(lexer, brace);
	else
		match_parameter(lexer);
	if (!error && lexer->index < lexer->size)
	{
		lexer->index--;
		vec_rm_last(lexer->slices);
	}
	return (error);
}
