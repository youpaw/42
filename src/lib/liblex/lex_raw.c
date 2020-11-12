//
// Created by youpaw on 6/14/20.
//

#include "lexer.h"
#include "cc_mem.h"
#include "cc_str.h"
#include "cc_num.h"
static void del_token(t_token *token)
{
	free(token->raw);
}

static void init_lexer(t_lexer *lexer, const char *raw, t_stage stage)
{
	t_slice	slice;

	lexer->raw = strdup(raw);
	lexer->begin = 0;
	lexer->index = 0;
	lexer->size = strlen(raw);
	lexer->slices = vec_new(SLICES_STACK_SIZE, sizeof(t_slice), NULL);
	lexer->tokens = vec_new(TOKENS_STACK_SIZE, sizeof(t_token),
							(void (*)(void *)) &del_token);
	lexer->stage = stage;
	bzero(lexer->flags, sizeof(char) * N_LEX_FLAGS);
	slice.state = l_unset;
	slice.index = 0;
	vec_push(lexer->slices, &slice);
}

int				lex_raw(t_lexer *lexer, const char *raw, t_stage stage)
{
	t_state		current;
	int			error;

	error = 0;
	init_lexer(lexer, raw, stage);
	while (lexer->index < lexer->size)
	{
		current = get_current_state(lexer);
		if ((error = lex_map(lexer, current)) != E_OK)
			break ;
		lexer->index++;
	}
	if (lexer->size && lexer->raw[lexer->size - 1] == '\4')
		return (E_EOF);
	return (error);
}
