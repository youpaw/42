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
		if (lexer->raw[lexer->begin] == '!')
			return (l_bang);
		if (get_valid_name_length(lexer->raw + lexer->begin))
			return (l_assignment_word);
		return (l_command_name);
	}
	vec_get_last(&token, lexer->tokens);
	if (is_redirection(token.type))
		return (l_filename);
	if (is_delimiter(token.type) && lexer->raw[lexer->begin] == '!')
		return (l_bang);
	if (token.type == l_assignment_word || token.type == l_bang || \
		token.type == l_filename || is_delimiter(token.type))
	{
		if (get_valid_name_length(lexer->raw + lexer->begin))
			return (l_assignment_word);
		return (l_command_name);
	}
	return (l_word);
}
