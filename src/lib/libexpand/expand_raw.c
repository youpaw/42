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
		'!',
		'~'
};

int (*g_handlers[N_STATES + 1])(t_expand *) = {
		&handle_back_slash,
		&handle_single_quote,
		&handle_double_quote,
		&handle_dollar,
		&handle_bang,
		&handle_tilda,
		&handle_unset
};

static t_state 	get_current_state(t_expand *expand)
{
	int		cnt;
	t_state	current;

	vec_get_last(&current, expand->states);
	if (current != e_unset)
		return (current);
	cnt = 0;
	while (cnt < N_STATES && g_state_map[cnt] != expand->raw[expand->index])
		cnt++;
	if (cnt < N_STATES)
	{
		expand->index++;
		vec_push(expand->states, &cnt);
	}
	return (cnt);
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
	expand->print_cmd = 0;
	state = e_unset;
	vec_push(expand->states, &state);
	return (expand);
}

int expand_raw(char **raw)
{
	t_expand	*expand;
	t_state		current;
	int error;

	if (!raw || !*raw || !**raw)
		return (E_NULL_INPUT);
	error = 0;
	expand = init_expand(*raw);
	while (expand->index < expand->size)
	{
		current = get_current_state(expand);
		if ((error = (*g_handlers[current])(expand)))
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
