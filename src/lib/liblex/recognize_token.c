//
// Created by Darth Butterwell on 8/26/20.
//

#include "lexer.h"
#include "env.h"

static int 		is_delimiter(t_token_type type)
{
	static const t_token_type delimiter_map[N_TOKEN_DELIMITERS] = {
			l_and_if, l_or_if, l_and, l_or, l_semi
	};
	int index;

	index = 0;
	while (index < N_TOKEN_DELIMITERS && type != delimiter_map[index])
		index++;
	if (index == N_TOKEN_DELIMITERS)
		return (0);
	return (1);
}

t_token_type recognize_token(t_lexer *lexer)
{
	t_token token;

	if (!lexer->tokens->size)
	{
		if (is_name_valid(lexer->raw + lexer->begin))
			return (l_assignment_word);
		return (l_command_name);
	}
	vec_get_last(&token, lexer->tokens);
	if (token.type == l_assignment_word || is_delimiter(token.type))
	{
		if (is_name_valid(lexer->raw + lexer->begin))
			return (l_assignment_word);
		return (l_command_name);
	}
	return (l_word);
}
