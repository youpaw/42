//
// Created by youpaw on 6/14/20.
//

#include "expand.h"
#include "string/cc_str.h"

static int 	handle_bs(t_expand *expand)
{
	char c;

	if (expand->index == expand->size - 1)
		return (E_INCOMPLETE_INPUT);
	c = expand->raw[expand->index];
	if (c == '\n')
	{
		strcpy(expand->raw + expand->index - 1, \
		expand->raw + expand->index + 1);
		expand->index -= 2;
		expand->size -= 2;
	}
	return (0);
}

static int 	handle_dq(t_expand *expand)
{
	char c;

	c = expand->raw[expand->index];
	if (c == '!')
		expand->state = e_bang;
	else if (c == '$')
		expand->state = e_dollar;
	else if (c == '\\')
		expand->index++;
	else if (c == '\"')
		expand->state = e_unset;
	return (0);
}

static int 	handle_bang(t_expand *expand)
{
	return (0);
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