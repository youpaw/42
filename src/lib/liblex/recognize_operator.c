//
// Created by Darth Butterwell on 8/26/20.
//

#include "lexer.h"
#include "cc_char.h"

static int is_redirection(t_token_type type)
{
	static const t_token_type redirection_map[N_TOKEN_REDIRECTIONS] = {
			l_less_and, l_great_and, l_less, l_great
	};
	int index;

	index = 0;
	while (index < N_TOKEN_REDIRECTIONS && type != redirection_map[index])
		index++;
	if (index == N_TOKEN_REDIRECTIONS)
		return (0);
	return (1);
}

static int is_number(const char *str)
{
	if (!str || !*str)
		return (0);
	while (isdigit(*str))
		str++;
	if (!*str)
		return (1);
	return (0);
}

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