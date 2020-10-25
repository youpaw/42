//
// Created by Darth Butterwell on 8/23/20.
//

#include "lexer.h"

int 		tok_bang(t_lexer *lexer)
{
	lexer->index--;
	vec_rm_last(lexer->slices);
	return (E_OK);
}