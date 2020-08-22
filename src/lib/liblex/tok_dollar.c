//
// Created by Darth Butterwell on 8/7/20.
//
#include "lexer.h"

static int validate_brace(t_lexer *lexer, t_vec *braces)
{
	t_brace current;
	t_brace last;
	int 	direction;

	if ((direction = get_brace(lexer->raw + lexer->index, &current)))
	{
		if (direction > 0)
			vec_push(braces, &braces);
		else
		{
			vec_get_last(&last, braces);
			if (last == current)
				vec_rm_last(braces);
			else
				return (E_BAD_SUBSTITUTION);
		}
	}
	return (0);
}

static int match_brace(t_lexer *lexer, t_brace brace)
{
	int		error;
	t_state current;
	t_vec	*braces;

	braces = vec_new(BRACES_STACK_SIZE, sizeof(t_brace), NULL);
	vec_push(braces, &brace);
	while (lexer->index < lexer->size && braces->size)
	{
		current = get_current_state(lexer);
		if ((error = lex_map(lexer, current)))
			break ;
		if (current == l_unset && (error = validate_brace(lexer, braces)))
			break ;
		lexer->index++;
	}
	if (!error && braces->size)
		error = E_INCOMPLETE_INPUT;
	vec_del(&braces);
	return (error);
}

int 	tok_dollar(t_lexer *lexer)
{
	t_brace	brace;
	t_state state;
	int		error;

	error = 0;
	if (get_brace(lexer->raw + lexer->index, &brace) > 0)
	{
		state = l_unset;
		vec_push(lexer->states, &state);
		lexer->index++;
		if (brace == l_double_round_brace)
			lexer->index++;
		error = match_brace(lexer, brace);
		vec_rm_last(lexer->states);
	}
	vec_rm_last(lexer->states);
	return (error);
}
