//
// Created by youpaw on 6/14/20.
//

#include "lexer.h"
#include <stdlib.h>
#include "cc_mem.h"
#include "cc_str.h"

static t_lexer *init_expand(char *raw, t_stage stage)
{
	t_lexer	*handle;
	t_state		state;

	handle = xmalloc(sizeof(t_lexer));
	handle->raw = raw;
	handle->index = 0;
	handle->size = strlen(raw);
	handle->states = vec_new(STATES_STACK_SIZE, sizeof(t_state), NULL);
	handle->stage = stage;
	bzero(handle->flags, sizeof(char) * N_LEX_FLAGS);
	state = l_unset;
	vec_push(handle->states, &state);
	return (handle);
}

static void 	del_expand(t_lexer *lexer)
{
	vec_del(&(lexer->states));
	free(lexer);
}

static void		clear_str(t_lexer *lexer)
{
	size_t padding;

	lexer->index = 0;
	padding = 0;
	while (lexer->index < lexer->size)
	{
		if (lexer->raw[lexer->index])
			lexer->raw[padding++] = lexer->raw[lexer->index++];
		else
			lexer->index++;
	}
	lexer->raw[padding] = '\0';
}

int				lex_raw(char **raw, t_stage stage)
{
	t_lexer	*handle;
	t_state		current;
	int			error;

	if (!raw || !*raw || !**raw)
		return (E_NULL_INPUT);
	error = 0;
	handle = init_expand(*raw, stage);
	while (handle->index < handle->size)
	{
		current = get_current_state(handle);
		if ((error = lex_map(handle, current)))
			break ;
		handle->index++;
	}
	if (!error && handle->states->size > 1)
		error = E_INCOMPLETE_INPUT;
	if (!error)
		clear_str(handle);
	del_expand(handle);
	return (error);
}
