//
// Created by Darth Butterwell on 9/13/20.
//

#include "lexer.h"
#include "cc_mem.h"
#include "cc_str.h"

t_tokens	*get_tokens(t_lexer *lexer, int error)
{
	t_tokens	*tokens;
	size_t		index;

	tokens = xmalloc(sizeof(t_tokens));
	lexer->raw[lexer->size - 1] = '\0';
	tokens->raw = strdup(lexer->raw);
	tokens->size = lexer->tokens->size;
	tokens->tokens = xmalloc(sizeof(t_token *) * tokens->size);
	tokens->index = 0;
	tokens->error = error;
	index = 0;
	while (index < tokens->size)
	{
		tokens->tokens[index] = xmalloc(sizeof(t_token));
		vec_get_at(tokens->tokens[index], lexer->tokens, index);
		index++;
	}
	free(lexer->tokens->data);
	free(lexer->tokens);
	lexer->tokens = NULL;
	return (tokens);
}
