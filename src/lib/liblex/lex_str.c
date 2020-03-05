#include "lexer.h"
#include <stdlib.h>
#include "lexer_internal.h"

void		destruct_tokens(t_tokens *tokens)
{
	int	i = -1;
	if (tokens->raw != NULL)
	{
		free(tokens->raw);
	}
	//while (++i < tokens->size)
	//{
	//	free_token(tokens->tokens + i);
	//}
	if (tokens->tokens != NULL)
	{
		free(tokens->tokens);
	}
}

t_tokens *create_empty_tokens()
{
	t_tokens *tokens;

	tokens = (t_tokens *)xmalloc(sizeof(t_tokens));

	tokens->size = 0;
	tokens->tokens = NULL;
	tokens->error = 0;
	tokens->raw = NULL;

	return (tokens);
}

t_tokens *lex_str(const char *string)
{
	t_tokens	*tokens;
	t_tlist *tlist;

	tlist = tokenize(string);
	tokens = to_tokens(tlist);
	destruct_tlist(tlist);
	return (tokens);
}