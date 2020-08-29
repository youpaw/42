//
// Created by Darth Butterwell on 8/29/20.
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
			if (vec_get_last(&last, braces) || last != current)
				return (E_BAD_SUBSTITUTION);
			else
				vec_rm_last(braces);
		}
		if (current == l_double_round_brace)
			lexer->index++;
	}
	return (0);
}

int match_brace(t_lexer *lexer, t_brace brace)
{
	int		error;
	t_state current;
	t_vec	*braces;

	braces = vec_new(BRACES_STACK_SIZE, sizeof(t_brace), NULL);
	vec_push(braces, &brace);
	lexer->index += brace == l_double_round_brace ? 2 : 1;
	current = l_unset;
	vec_push(lexer->states, &current);
	while (lexer->index < lexer->size && braces->size)
	{
		current = get_current_state(lexer);
		if ((current != l_unset && (error = lex_map(lexer, current))) || \
		(current == l_unset && (error = validate_brace(lexer, braces))))
			break ;
		lexer->index++;
	}
	if (!error && braces->size)
		error = E_INCOMPLETE_INPUT;
	else
		vec_rm_last(lexer->states);
	vec_del(&braces);
	return (error);
}