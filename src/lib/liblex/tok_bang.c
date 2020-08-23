//
// Created by Darth Butterwell on 8/23/20.
//

#include "lexer.h"

int 		tok_bang(t_lexer *lexer)
{
	vec_rm_last(lexer->states);
	return (0);
}