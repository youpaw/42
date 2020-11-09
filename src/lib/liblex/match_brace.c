//
// Created by Darth Butterwell on 8/29/20.
//

#include "lexer.h"

static int		validate_brace(t_lexer *lexer, t_vec *braces)
{
	t_brace	current;
	t_brace	last;
	int		direction;

	if ((direction = get_brace(lexer->raw + lexer->index, &current)))
	{
		if (direction > 0)
			vec_push(braces, &current);
		else
		{
			if (!vec_get_last(&last, braces) && last == current)
				vec_rm_last(braces);
		}
	}
	return (E_OK);
}

int				match_brace(t_lexer *lexer, t_brace brace)
{
	int		error;
	t_slice	current;
	t_vec	*braces;

	braces = vec_new(BRACES_STACK_SIZE, sizeof(t_brace), NULL);
	vec_push(braces, &brace);
	lexer->index++;
	current.state = l_unset;
	current.index = lexer->index;
	vec_push(lexer->slices, &current);
	error = 0;
	while (lexer->index < lexer->size && braces->size)
	{
		current.state = get_current_state(lexer);
		if ((current.state != l_unset
		&& (error = lex_map(lexer, current.state))) || (current.state == l_unset
		&& (error = validate_brace(lexer, braces))))
			break ;
		lexer->index++;
	}
	if (!error && braces->size)
		error = E_INCINP;
	vec_rm_last(lexer->slices);
	vec_del(&braces);
	return (error);
}
