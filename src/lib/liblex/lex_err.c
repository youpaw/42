//
// Created by Darth Butterwell on 9/13/20.
//

#include "lexer.h"

int								lex_err(t_lexer *lexer, int error)
{
	static const t_token_type	inc_types_map[N_INC_INP_TYPES] = {
			l_and_if, l_or_if, l_or
	};
	int							index;
	t_token						last_token;

	if (!error && lexer->slices->size > 1)
		error = E_INCINP;
	if (!error && lexer->tokens->size)
	{
		vec_get_last(&last_token, lexer->tokens);
		if (lexer->tokens->size == 1 && last_token.type == l_newline)
			error = E_NOINP;
		else
		{
			index = 0;
			while (index < N_INC_INP_TYPES && \
			inc_types_map[index] != last_token.type)
				index++;
			if (index < N_INC_INP_TYPES)
				error = E_INCINP;
		}
	}
	return (error);
}
