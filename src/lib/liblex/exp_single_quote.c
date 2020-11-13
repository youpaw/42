//
// Created by Darth Butterwell on 8/26/20.
//

#include "lexer.h"
#include "cc_mem.h"

int		exp_single_quote(t_lexer *lexer)
{
	memmove(lexer->raw + lexer->index - 1, lexer->raw + lexer->index,
		lexer->size - lexer->index + 1);
	lexer->index--;
	lexer->size--;
	while (lexer->raw[lexer->index] != '\'' && lexer->index < lexer->size)
		lexer->index++;
	memmove(lexer->raw + lexer->index, lexer->raw + lexer->index + 1,
		lexer->size - lexer->index);
	lexer->index--;
	lexer->size--;
	vec_rm_last(lexer->slices);
	return (E_OK);
}
