//
// Created by Darth Butterwell on 8/23/20.
//

#include "lexer.h"
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
	t_slice slice;

	token.raw = strsub(lexer->raw, lexer->begin, token_size);
	token.type = type;
	vec_push(lexer->tokens, &token);
	if (type == l_double_less)
	{
		slice.index = lexer->index;
		slice.state = l_heredoc;
		vec_push(lexer->slices, &slice);
	}
	lexer->index += token_size - 1;
	lexer->begin = lexer->index + 1;
}

static void	recognize_io_number(t_lexer *lexer, t_token_type type)
{
	t_token token;

	if (is_redirection(type))
	{
		vec_get_last(&token, lexer->tokens);
		if (is_number(token.raw))
		{
			vec_rm_last(lexer->tokens);
			token.type = l_io_number;
			vec_push(lexer->tokens, &token);
		}
	}
}

int 		tok_unset(t_lexer *lexer)
{
	char		c;
	t_operator	op;
	t_token_type type;

	c = lexer->raw[lexer->index];
	if (c == ' ' || c == '\t' || !c)
	{
		if (lexer->begin == lexer->index)
			lexer->begin++;
		else
			delimit_token(lexer);
	}
	else if ((type = get_operator(lexer->raw + lexer->index, &op)) != l_token)
	{
		if (lexer->begin < lexer->index)
		{
			delimit_token(lexer);
			recognize_io_number(lexer, type);
		}
		lexer->begin = lexer->index;
		delimit_operator(lexer, type, op.size);
	}
	return (E_OK);
}