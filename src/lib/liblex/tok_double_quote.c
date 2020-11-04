//
// Created by Darth Butterwell on 8/7/20.
//

#include "lexer.h"

int 	tok_double_quote(t_lexer *lexer)
{
	t_slice slice;
	char c;

	slice.state = l_unset;
	c = lexer->raw[lexer->index];
	if (c == '!')
		slice.state = l_history;
	else if (c == '$')
		slice.state = l_dollar;
	else if (c == '\\' && is_doublequote_esc(lexer->raw[lexer->index + 1]))
		slice.state = l_back_slash;
	else if (c == '\"')
		vec_rm_last(lexer->slices);
	if (slice.state != l_unset)
	{
		slice.index = lexer->index;
		vec_push(lexer->slices, &slice);
	}
	return (E_OK);
}