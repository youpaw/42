//
// Created by youpaw on 6/14/20.
//

#include "lexer.h"
#include "cc_mem.h"
#include "cc_str.h"

int		init_lexer(t_lexer *lexer, char *raw, t_stage stage)
{
	t_state	state;

	if (!raw || !*raw)
		return (E_NULL_INPUT);
	lexer->raw = strdup(raw);
	lexer->begin = 0;
	lexer->index = 0;
	lexer->size = strlen(raw);
	lexer->states = vec_new(STATES_STACK_SIZE, sizeof(t_state), NULL);
	lexer->tokens = vec_new(TOKENS_STACK_SIZE, sizeof(t_token), NULL);
	lexer->stage = stage;
	bzero(lexer->flags, sizeof(char) * N_LEX_FLAGS);
	state = l_unset;
	vec_push(lexer->states, &state);
	return (0);
}

static void 	del_lexer(t_lexer *lexer)
{
	vec_del(&(lexer->states));
	vec_del(&(lexer->tokens));
}

static t_tokens	*get_tokens(t_lexer *lexer, int error)
{
	t_tokens	*tokens;
	size_t		index;

	tokens = xmalloc(sizeof(t_tokens));
	tokens->raw = lexer->raw;
	tokens->error = error;
	tokens->size = lexer->tokens->size;
	tokens->tokens = xmalloc(sizeof(t_token *) * tokens->size);
	index = 0;
	while (index < tokens->size)
	{
		tokens->tokens[index] = xmalloc(sizeof(t_token));
		vec_get_at(tokens->tokens[index], lexer->tokens, index);
		index++;
	}
	return (tokens);
}

t_tokens 	*lex_raw(char *raw, t_stage stage)
{
	t_lexer		lexer;
	t_tokens	*tokens;
	t_state		current;
	int			error;

	if (init_lexer(&lexer, raw, stage))
		return (NULL);
	error = 0;
	while (lexer.index <= lexer.size)
	{
		current = get_current_state(&lexer);
		if ((error = lex_map(&lexer, current)))
			break ;
		lexer.index++;
	}
	if (!error && lexer.states->size > 1)
		error = E_INCOMPLETE_INPUT;
	tokens = get_tokens(&lexer, error);
	del_lexer(&lexer);
	return (tokens);
}
