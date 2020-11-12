//
// Created by Darth Butterwell on 8/26/20.
//

#include "lexer.h"
#include "cc_mem.h"

static void	remove_quotes(t_lexer *lexer)
{
	t_slice		slice;

	vec_get_last(&slice, lexer->slices);
	memmove(lexer->raw + slice.index, lexer->raw + slice.index + 1,
			lexer->index - slice.index - 1);
	memmove(lexer->raw + lexer->index - 1, lexer->raw + lexer->index + 1,
			lexer->size - lexer->index);
	lexer->index -= 2;
	lexer->size -= 2;
	vec_rm_last(lexer->slices);
}

int			exp_double_quote(t_lexer *lexer)
{
	t_slice		slice;
	char		c;

	slice.state = l_unset;
	c = lexer->raw[lexer->index];
	if (c == '!')
		slice.state = l_history;
	else if (c == '$')
		slice.state = l_dollar;
	else if (c == '\\' && is_doublequote_esc(lexer->raw[lexer->index + 1]))
		slice.state = l_back_slash;
	else if (c == '\"')
	{
		remove_quotes(lexer);
		slice.state = l_unset;
	}
	if (slice.state != l_unset)
	{
		slice.index = lexer->index;
		vec_push(lexer->slices, &slice);
	}
	return (E_OK);
}
