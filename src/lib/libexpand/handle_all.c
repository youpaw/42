//
// Created by Darth Butterwell on 8/9/20.
//

#include "expand.h"

int		handle_all(t_handle *handle, t_state current)
{
	static int	(*handlers[N_EXPAND_STAGES][N_STATES])(t_handle *) = {
			{&validate_back_slash, &validate_single_quote, \
            &validate_double_quote, &validate_dollar, \
            &validate_bang, NULL},
			{&expand_back_slash,   &validate_single_quote, \
            &validate_double_quote, &expand_dollar, \
			NULL, &expand_tilda}
	};

	if (current != e_unset)
	{
		if (*handlers[handle->stage][current])
			return ((*handlers[handle->stage][current])(handle));
		else
			vec_rm_last(handle->states);
	}
	return (0);
}