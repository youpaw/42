//
// Created by Darth Butterwell on 8/23/20.
//

#include "lexer.h"
#include "cc_str.h"

t_tokens	*tokenize_str_sub(const char *string, size_t len)
{
	t_lexer		lexer;
	t_tokens	*tokens;
	char		*sub;
	int			error;

	if (!string || !*string)
		return (NULL);
	sub = strsub(string, 0, len);
	error = lex_err(&lexer, lex_raw(&lexer, sub, l_tok));
	tokens = get_tokens(&lexer, error);
	lex_del(&lexer);
	free(sub);
	return (tokens);
}