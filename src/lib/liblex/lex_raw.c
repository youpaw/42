//
// Created by youpaw on 6/14/20.
//

#include "lexer.h"
#include "cc_mem.h"
#include "cc_str.h"

static int init_lexer(t_lexer *lexer, const char *raw, t_stage stage)
{
	t_state	state;

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
	return (E_OK);
}

int				lex_raw(t_lexer *lexer, const char *raw, t_stage stage)
{
	t_state		current;
	int			error;

	if ((error = init_lexer(lexer, raw, stage)))
		return (error);
	while (lexer->index <= lexer->size)
	{
		current = get_current_state(lexer);
		if ((error = lex_map(lexer, current)) != E_OK)
			break ;
		lexer->index++;
	}
	return (error);
}
