//
// Created by Darth Butterwell on 8/23/20.
//

#include "lexer.h"
#include "cc_str.h"

t_tokens	*lex_str_len(const char *string, t_stage stage, size_t len)
{
	t_tokens	*tokens;
	char		*sub;

	if (!string || !*string)
		return (NULL);
	sub = strsub(string, 0, len);
	tokens = lex_raw(sub, stage);
	recognize_tokens(tokens);
	free(sub);
	return (tokens);
}