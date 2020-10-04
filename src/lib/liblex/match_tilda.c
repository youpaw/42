//
// Created by youpaw on 9/24/20.
//
#include "lexer.h"
#include "cc_char.h"

int 		match_tilda(t_lexer *lexer)
{
	char c;

	if (lexer->index)
	{
		c = lexer->raw[lexer->index - 1];
		if (!iswspace(c))
			return (1);
	}
	c = lexer->raw[lexer->index++];
	if (c != '~')
		return (1);
	c = lexer->raw[lexer->index++];
	if (c == '+' || c == '-')
		c = lexer->raw[lexer->index++];
	if (c && c != '/' && !iswspace(c))
		return (1);
	return (0);
}