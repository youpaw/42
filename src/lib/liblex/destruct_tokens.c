//
// Created by Darth Butterwell on 8/23/20.
//

#include "lexer.h"

void 		destruct_tokens(t_tokens **tokens)
{
	t_tokens	*p_tokens;
	size_t		index;

	if (!tokens || !*tokens)
		return ;
	index = 0;
	p_tokens = *tokens;
	while (index < p_tokens->size)
	{
		destruct_token(&p_tokens->tokens[index]);
		index++;
	}
	free(p_tokens->tokens);
	free(p_tokens->raw);
	free(p_tokens);
	*tokens = NULL;
}