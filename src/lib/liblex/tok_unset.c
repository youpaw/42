//
// Created by Darth Butterwell on 8/23/20.
//

#include "lexer.h"
#include "env.h"
#include "cc_char.h"
#include "cc_str.h"

static void delimit_token(t_lexer *lexer)
{
	t_token token;

	token.raw = strsub(lexer->raw, lexer->begin, lexer->index - lexer->begin);
	if (is_name_valid(token.raw))
		token.type = l_assignment_word;
	else
		token.type = l_word;
	vec_push(lexer->tokens, &token);
	lexer->begin = lexer->index + 1;
}

static void delimit_operator(t_lexer *lexer, t_token_type type, int token_size)
{
	t_token token;

	token.raw = strsub(lexer->raw, lexer->begin, token_size);
	token.type = type;
	vec_push(lexer->tokens, &token);
	lexer->index += token_size - 1;
	lexer->begin = lexer->index + 1;
}

static void	get_operator(t_lexer *lexer)
{
	static char *operators_map[N_TOKEN_OPERATORS] = {
			""
	};
}

int 		tok_unset(t_lexer *lexer)
{
	char c;

	c = lexer->raw[lexer->index];
	if (iswspace(c))
	{
		if (lexer->begin == lexer->index)
			lexer->begin++;
		else
			delimit_token(lexer);
		return (0);
	}
}