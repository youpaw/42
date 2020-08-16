//
// Created by Darth Butterwell on 8/9/20.
//
#include "expand.h"

t_state 	get_current_state(t_handle *expand)
{
	int					cnt;
	t_state				current;
	static const char	state_map[N_STATES] = {'\\', '\'', '"', '$', '!', '~'};

	vec_get_last(&current, expand->states);
	if (current != e_unset)
		return (current);
	cnt = 0;
	while (cnt < N_STATES && state_map[cnt] != expand->raw[expand->index])
		cnt++;
	if (cnt < N_STATES)
	{
		expand->index++;
		vec_push(expand->states, &cnt);
	}
	return (cnt);
}