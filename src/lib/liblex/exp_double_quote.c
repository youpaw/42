//
// Created by Darth Butterwell on 8/26/20.
//

#include "lexer.h"
#include "cc_mem.h"

int 		exp_double_quote(t_lexer *lexer)
{
	t_state state;
	char c;

	memmove(lexer->raw + lexer->index - 1, lexer->raw + lexer->index, lexer->size - lexer->index + 1);
	lexer->index--;
	lexer->size--;
	state = l_unset;
	c = lexer->raw[lexer->index];
	if (c == '!')
		state = l_history;
	else if (c == '$')
		state = l_dollar;
	else if (c == '\\')
		state = l_back_slash;
	else if (c == '\"')
	{
		memmove(lexer->raw + lexer->index, lexer->raw + lexer->index + 1, lexer->size - lexer->index + 1);
		lexer->index--;
		lexer->size--;
		vec_rm_last(lexer->states);
	}
	if (state != l_unset)
		vec_push(lexer->states, &state);
	return (E_OK);
}