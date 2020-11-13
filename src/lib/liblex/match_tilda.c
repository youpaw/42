//
// Created by youpaw on 9/24/20.
//
#include "lexer.h"

int		match_tilda(t_lexer *lexer)
{
	char c;

	if (lexer->index)
		return (1);
	c = lexer->raw[lexer->index++];
	if (c != '~')
		return (1);
	if (lexer->index < lexer->size)
		c = lexer->raw[lexer->index++];
	else
		return (0);
	if (c == '+' || c == '-')
		c = lexer->raw[lexer->index++];
	if (c && c != '/')
		return (1);
	if (c == '/')
		lexer->index--;
	return (0);
}
