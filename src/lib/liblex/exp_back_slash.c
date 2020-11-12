//
// Created by Darth Butterwell on 8/8/20.
//

#include "lexer.h"
#include "cc_mem.h"

int		exp_back_slash(t_lexer *lexer)
{
	memmove(lexer->raw + lexer->index - 1, lexer->raw + lexer->index,
		lexer->size - lexer->index + 1);
	lexer->index--;
	lexer->size--;
	vec_rm_last(lexer->slices);
	return (E_OK);
}
