//
// Created by Darth Butterwell on 8/9/20.
//

#include "lexer.h"

int		lex_map(t_lexer *tokenize, t_state current)
{
	static int	(*handlers[N_LEX_STAGES][N_STATES + 1])(t_lexer *) = {
			{NULL},
			{&vld_back_slash, &tok_single_quote, \
            &tok_double_quote, &tok_dollar, \
            &vld_bang, NULL},
			{&exp_back_slash, &tok_single_quote, \
            &tok_double_quote, &exp_dollar, \
			NULL, NULL}
	};

	if (*handlers[tokenize->stage][current])
		return ((*handlers[tokenize->stage][current])(tokenize));
	else
		vec_rm_last(tokenize->states);
	return (0);
}