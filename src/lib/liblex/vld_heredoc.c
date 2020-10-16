//
// Created by Darth Butterwell on 10/16/20.
//

#include "lexer.h"

static int	match_end(t_lexer *lexer, t_token *end)
{

}

static int get_end(t_vec *tokens, size_t start_token_index, t_token *token)
{
	size_t index;

	index = tokens->size - 1;
	if (index == start_token_index)
		return (1);
}

int 		vld_heredoc(t_lexer *lexer)
{
	t_token	end;
	size_t	start_token_index;
	t_state current;
	t_slice slice;
	int error;

	error = 0;
	start_token_index = lexer->tokens->size - 1;
	slice.index = lexer->index;
	slice.state = l_unset;
	vec_push(lexer->slices, &slice);
	while (lexer->index < lexer->size && lexer->raw[lexer->index] != '\n')
	{
		current = get_current_state(lexer);
		if ((error = lex_map(lexer, current)) != E_OK)
			break ;
		lexer->index++;
	}
	if (!error && lexer->index == lexer->size)
		error = E_INCINP;
	else if (!(error = get_end(lexer->tokens, start_token_index, &end)))
		error = match_end(lexer, &end);
	return (error);
}