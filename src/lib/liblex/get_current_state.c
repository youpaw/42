//
// Created by Darth Butterwell on 8/9/20.
//
#include "lexer.h"

t_state		get_current_state(t_lexer *lexer)
{
	int					cnt;
	t_slice				current;
	static const char	state_map[N_STATES - 1] = {'\\', '\'', '"', '$', '!'};

	vec_get_last(&current, lexer->slices);
	if (current.state != l_unset)
		return (current.state);
	cnt = 0;
	while (cnt < (N_STATES - 1) && state_map[cnt] != lexer->raw[lexer->index])
		cnt++;
	if (cnt < (N_STATES - 1))
	{
		current.state = cnt;
		current.index = lexer->index;
		vec_push(lexer->slices, &current);
		lexer->index++;
	}
	else
		return (l_unset);
	return (cnt);
}
