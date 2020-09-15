//
// Created by Darth Butterwell on 8/9/20.
//

#include "lexer.h"

int		lex_map(t_lexer *lexer, t_state current)
{
	static int	(*handlers[N_LEX_STAGES][N_STATES + 1])(t_lexer *) = {
			{&tok_back_slash, &tok_single_quote, &tok_double_quote, \
			&tok_dollar, &tok_bang, &tok_unset},
			{&vld_back_slash, &tok_single_quote, &tok_double_quote, \
			&tok_dollar, &vld_bang, &tok_unset},
			{&exp_back_slash, &exp_single_quote, &exp_double_quote, \
			&exp_dollar, NULL, &exp_unset}
	};

	if (*handlers[lexer->stage][current])
		return ((*handlers[lexer->stage][current])(lexer));
	else
		vec_rm_last(lexer->states);
	return (0);
}