//
// Created by Darth Butterwell on 8/28/20.
//

#include "lexer.h"
#include "cc_str.h"
#include "cc_mem.h"

static t_token *init_token(void)
{
	t_token *token;

	token = xmalloc(sizeof(t_token));
	token->raw = NULL;
	token->type = l_token;
	return (token);
}

t_token		*get_last_token(t_tokens *tokens)
{
	t_token *token;
	t_token *last_token;

	token = init_token();
	last_token = tokens->size ? tokens->tokens[tokens->size - 1] : NULL;
	if (!last_token || is_delimiter(last_token->type))
	{
		token->raw = strdup("");
		token->type = l_command_name;
	}
	else
	{
		token->raw = strdup(last_token->raw);
		token->type = last_token->type;
	}
	return (token);
}