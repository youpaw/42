//
// Created by Darth Butterwell on 8/7/20.
//

#include "lexer.h"

int 	tok_double_quote(t_lexer *lexer)
{
	t_state state;
	char c;

	state = l_unset;
	c = lexer->raw[lexer->index];
	if (c == '!')
		state = l_bang;
	else if (c == '$')
		state = l_dollar;
	else if (c == '\\')
		state = l_back_slash;
	else if (c == '\"')
		vec_rm_last(lexer->states);
	if (state != l_unset)
		vec_push(lexer->states, &state);
	return (E_OK);
}