//
// Created by Darth Butterwell on 8/26/20.
//

#include "lexer.h"
#include "expand.h"
#include "cc_str.h"

int 		exp_unset(t_lexer *lexer)
{
	char	*sub;
	size_t index;

	index = lexer->index;
	if (!match_tilda(lexer))
	{
		sub = strsub(lexer->raw, index, lexer->index - index);
		expand_tilda(&sub);
		strjoin_expanded(lexer, index, sub, 0);
		free(sub);
	}
	return (E_OK);
}