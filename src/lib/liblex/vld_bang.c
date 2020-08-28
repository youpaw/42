//
// Created by Darth Butterwell on 8/7/20.
//

#include "lexer.h"

int 	vld_bang(t_lexer *lexer)
{
	vec_rm_last(lexer->states);
	return (0);
}