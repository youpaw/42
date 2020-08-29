//
// Created by Darth Butterwell on 8/26/20.
//

#include "lexer.h"

t_token_type recognize_operator(t_lexer *lexer, t_token_type type)
{
	t_token token;

	if (!is_redirection(type) || !lexer->tokens->size)
		return (type);
	vec_get_last(&token, lexer->tokens);
	if (is_number(token.raw))
		return (l_io_number);
	return (type);
}