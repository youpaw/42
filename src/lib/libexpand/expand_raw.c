//
// Created by youpaw on 6/14/20.
//

#include "expand.h"
#include <stdlib.h>
#include "memory/cc_mem.h"
#include "string/cc_str.h"

const char g_state_map[N_STATES] = {
		'\\',
		'\'',
		'"',
		'$',
		'!'
};

static t_state 	get_current_state(t_expand *expand)
{
	int		cnt;
	t_state	current;

	vec_get_last(&current, expand->states);
	if (current == e_single_quote)
		return (current);
	cnt = 0;
	while (cnt < N_STATES && g_state_map[cnt] != expand->raw[expand->index])
		cnt++;
	if (cnt < N_STATES)
	{
		if (cnt == e_dollar)
			expand->flags[e_handling_dollar] = 1;
		vec_push(expand->states, &cnt);
		expand->index++;
		return (cnt);
	}
	return (e_unset);
}

static t_expand *init_expand(char *raw)
{
	t_expand	*expand;
	t_state		state;

	expand = xmalloc(sizeof(t_expand));
	expand->raw = raw;
	expand->index = 0;
	expand->size = strlen(raw);
	expand->states = vec_new(STATES_STACK_SIZE, sizeof(t_state), NULL);
	bzero(expand->flags, 2);
	state = e_unset;
	vec_push(expand->states, &state);
	return (expand);
}

int expand_raw(char **raw, int (*handler)(t_state, t_expand *), \
			   int (*dollar_handler)(t_expand *))
{
	t_expand	*expand;
	t_state		current;
	int error;

	error = 0;
	expand = init_expand(*raw);
	while (expand->index < expand->size)
	{
		current = get_current_state(expand);
		if ((current == e_dollar && (error = dollar_handler(expand))) || \
			(error = handler(current, expand)))
			break ;
		expand->index++;
	}
	if (!error && expand->states->size > 1)
		error = E_INCOMPLETE_INPUT;
	*raw = expand->raw;
	vec_del(&(expand->states));
	free(expand);
	return (error);
}
