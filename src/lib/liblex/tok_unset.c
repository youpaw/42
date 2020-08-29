//
// Created by Darth Butterwell on 8/23/20.
//

#include "lexer.h"
#include "cc_char.h"
#include "cc_str.h"

static void delimit_token(t_lexer *lexer)
{
	t_token token;

	token.raw = strsub(lexer->raw, lexer->begin, lexer->index - lexer->begin);
	token.type = recognize_token(lexer);
	vec_push(lexer->tokens, &token);
	lexer->begin = lexer->index + 1;
}

static void delimit_operator(t_lexer *lexer, t_token_type type, int token_size)
{
	t_token token;

	token.raw = strsub(lexer->raw, lexer->begin, token_size);
	token.type = recognize_operator(lexer, type);
	vec_push(lexer->tokens, &token);
	lexer->index += token_size - 1;
	lexer->begin = lexer->index + 1;
}

int 		tok_unset(t_lexer *lexer)
{
	char		c;
	t_operator	op;
	t_token_type type;

	c = lexer->raw[lexer->index];
	if (iswspace(c) || !c)
	{
		if (lexer->begin == lexer->index)
			lexer->begin++;
		else
			delimit_token(lexer);
	}
	else if ((type = get_operator(lexer->raw + lexer->index, &op)) != l_token)
	{
		delimit_token(lexer);
		lexer->begin = lexer->index;
		delimit_operator(lexer, type, op.size);
	}
	return (0);
}