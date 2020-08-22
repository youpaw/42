//
// Created by Darth Butterwell on 8/7/20.
//

#include "lexer.h"
#include "cc_mem.h"

int 	vld_back_slash(t_lexer *lexer)
{
	char c;

	c = lexer->raw[lexer->index];
	if (c == '\n')
	{
		if (lexer->index == lexer->size - 1)
			return (E_INCOMPLETE_INPUT);
		bzero(lexer->raw + lexer->index - 1, 2);
	}
	vec_rm_last(lexer->states);
	return (0);
}