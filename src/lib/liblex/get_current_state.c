//
// Created by Darth Butterwell on 8/9/20.
//
#include "lexer.h"

t_state 	get_current_state(t_lexer *lexer)
{
	int					cnt;
	t_state				current;
	static const char	state_map[N_STATES] = {'\\', '\'', '"', '$', '!'};

	vec_get_last(&current, lexer->states);
	if (current != l_unset)
		return (current);
	cnt = 0;
	while (cnt < N_STATES && state_map[cnt] != lexer->raw[lexer->index])
		cnt++;
	if (cnt < N_STATES)
	{
		lexer->index++;
		vec_push(lexer->states, &cnt);
	}
	return (cnt);
}