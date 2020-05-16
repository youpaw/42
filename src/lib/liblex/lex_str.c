//
// Created by youpaw on 04.05.2020.
//

#include "lexer.h"
#include "lex_recognize.h"
#include "lex_validate.h"
#include "cc.h"

static t_tokens *init_tokens_struct(const char *string)
{
	t_tokens *tokens;

	tokens = xmalloc(sizeof(t_tokens));
	tokens->raw = strdup(string);
	tokens->error = E_OK;
	tokens->tokens = NULL;
	tokens->size = 0;
	return (tokens);
}

t_tokens	*lex_str(const char *string)
{
	t_tokens *tokens;

	tokens = init_tokens_struct(string);
	if ((tokens->error = validate_input(&(tokens->raw))))
		return (tokens);
	//write raw to history
	recognize_tokens(tokens);
	return (tokens);
}