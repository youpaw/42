//
// Created by youpaw on 6/14/20.
//

#include "expand.h"

static int 	handle_bs(t_expand *expand)
{

}

static int 	handle_dq(t_expand *expand)
{

}

static int 	handle_bang(t_expand *expand)
{

}

static int 	handle_dollar(t_expand *expand)
{

}

int 	validate_input_handler(t_expand *expand)
{
	int error;

	if (expand->state == e_back_slash)
		error = handle_bs(expand);
	else if (expand->state == e_double_quote)
		error = handle_dq(expand);
	else if (expand->state == e_bang)
		error = handle_bang(expand);
	else if (expand->state == e_dollar)
		error = handle_dollar(expand);
	error = 0;
	return (error);
}