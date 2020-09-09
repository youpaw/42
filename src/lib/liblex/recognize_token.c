//
// Created by Darth Butterwell on 8/26/20.
//

#include "lexer.h"
#include "env.h"

t_token_type recognize_token(t_lexer *lexer)
{
	t_token token;

	if (!lexer->tokens->size)
	{
		if (get_valid_name_length(lexer->raw + lexer->begin))
			return (l_assignment_word);
		return (l_command_name);
	}
	vec_get_last(&token, lexer->tokens);
	if (token.type == l_assignment_word || is_delimiter(token.type))
	{
		if (get_valid_name_length(lexer->raw + lexer->begin))
			return (l_assignment_word);
		return (l_command_name);
	}
	return (l_word);
}
