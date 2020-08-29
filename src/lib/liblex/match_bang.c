//
// Created by Darth Butterwell on 8/29/20.
//

#include "lexer.h"
#include "cc_char.h"

static int	match_prev(t_lexer *lexer)
{
	if (lexer->raw[lexer->index] == '!')
		lexer->index++;
	else
		return (1);
	return (0);
}

static int	match_num(t_lexer *lexer)
{
	if (isdigit(lexer->raw[lexer->index]))
	{
		lexer->index++;
		while (lexer->index < lexer->size && isdigit(lexer->raw[lexer->index]))
			lexer->index++;
	}
	else if (lexer->raw[lexer->index] == '-' && \
	isdigit(lexer->raw[lexer->index + 1]))
	{
		lexer->index += 2;
		while (lexer->index < lexer->size && isdigit(lexer->raw[lexer->index]))
			lexer->index++;
	}
	else
		return (1);
	return (0);
}

static int	match_word(t_lexer *lexer)
{
	char c;
	t_brace brace;
	t_state current;

	vec_get_last(&current, lexer->states);
	while (lexer->index < lexer->size)
	{
		c = lexer->raw[lexer->index];
		if (iswspace(c) || get_brace(lexer->raw + lexer->index, &brace) || \
		(current == l_double_quote && c == '"'))
			break ;
		lexer->index++;
	}
	return (0);
}

int 		match_bang(t_lexer *lexer)
{
	if (lexer->index >= lexer->size)
		return (1);
	if (match_prev(lexer) && match_num(lexer))
		return (match_word(lexer));
}