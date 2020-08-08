//
// Created by youpaw on 6/14/20.
//

#include "expand.h"
#include <stdlib.h>
#include "memory/cc_mem.h"
#include "string/cc_str.h"

const char		g_state_map[N_STATES] = {
		'\\',
		'\'',
		'"',
		'$',
		'!',
		'~'
};

int				(*g_handlers[N_EXPAND_CONF][N_STATES + 1])(t_expand *) = {
		{&input_handle_back_slash, &handle_single_quote, &handle_double_quote, \
		&input_handle_dollar, &input_handle_bang, NULL, &handle_unset},
		{&exec_handle_back_slash, &handle_single_quote, &handle_double_quote, \
		&exec_handle_dollar, NULL, &exec_handle_tilda, &handle_unset}
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
		if (cnt == e_dollar)
			expand->flags[e_handling_dollar] = 1;
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
	expand->braces = vec_new(BRACES_STACK_SIZE, sizeof(t_brace), NULL);
	bzero(expand->flags, sizeof(char) * N_EXPAND_FLAGS);
	state = e_unset;
	vec_push(expand->states, &state);
	return (expand);
}

static void 	del_expand(char **raw, t_expand *expand)
{
	*raw = expand->raw;
	vec_del(&(expand->states));
	vec_del(&(expand->braces));
	free(expand);
}

int				expand_raw(char **raw, t_conf conf)
{
	t_expand	*expand;
	t_state		current;
	int			error;

	if (!raw || !*raw || !**raw)
		return (E_NULL_INPUT);
	error = 0;
	expand = init_expand(*raw);
	while (expand->index < expand->size)
	{
		current = get_current_state(expand);
		if ((*g_handlers[conf][current]))
			if ((error = (*g_handlers[conf][current])(expand)))
				break ;
		expand->index++;
	}
	if (!error && expand->states->size > 1)
		error = E_INCOMPLETE_INPUT;
	del_expand(raw, expand);
	return (error);
}
