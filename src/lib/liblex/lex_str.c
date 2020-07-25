//
// Created by youpaw on 04.05.2020.
//

#include "lexer.h"
#include "cc.h"

static t_tokens *init_tokens_struct(const char *string)
{
	t_tokens *tokens;

	tokens = xmalloc(sizeof(t_tokens));
	tokens->raw = strdup(string);
	tokens->error = 0;
	tokens->tokens = NULL;
	tokens->size = 0;
	return (tokens);
}

t_tokens	*lex_str(const char *string)
{
	t_tokens *tokens;

	tokens = init_tokens_struct(string);
	//validate input
	//write raw to history
	//expand substitutions
	//recognize




	return (tokens);
}