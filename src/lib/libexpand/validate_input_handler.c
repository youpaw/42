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
	vec_rm_last(expand->states);
	return (0);
}

static int 	handle_dq(t_expand *expand)
{
	char c;

	c = expand->raw[expand->index];
	if (c == '!')
		vec_push(expand->states, (void *)e_bang);
	else if (c == '$')
		vec_push(expand->states, (void *)e_dollar);
	else if (c == '\\')
		expand->index++;
	else if (c == '\"')
		vec_rm_last(expand->states);
	return (0);
}

static int 	handle_sq(t_expand *expand)
{
	while (expand->raw[expand->index] != '\'' && expand->index < expand->size)
		expand->index++;
	if (expand->index == expand->size)
		return (E_INCOMPLETE_INPUT);
	vec_rm_last(expand->states);
	return (0);
}

int expand_input_handler(t_state current, t_expand *expand)
{
	int error;

	error = 0;
	if (current == e_back_slash)
		error = handle_bs(expand);
	else if (current == e_double_quote)
		error = handle_dq(expand);
	else if (current == e_single_quote)
		error = handle_sq(expand);
	return (error);
}