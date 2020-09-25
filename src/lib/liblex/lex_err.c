//
// Created by Darth Butterwell on 9/13/20.
//

#include "lexer.h"
int								lex_err(t_lexer *lexer, int error)
{
	static const t_token_type	inc_types_map[] = {
			l_and_if, l_or_if, l_or, -1
	};
	int							index;
	t_token						last_token;

	if (!error && lexer->slices->size > 1)
		error = E_INCINP;
	if (!error && lexer->tokens->size && \
	vec_get_last(&last_token, lexer->tokens))
	{
		index = 0;
		while (inc_types_map[index] >= 0 && \
		inc_types_map[index] != last_token.type)
			index++;
		if (inc_types_map[index] >= 0)
			error = E_INCINP;
	}
	return (error);
}
