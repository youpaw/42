//
// Created by youpaw on 6/14/20.
//

#include "expand.h"
#include <stdlib.h>
#include "memory/cc_mem.h"
#include "string/cc_str.h"

static void 	handle_single_quote(t_expand *expand)
{
	if (expand->raw[expand->index] == '\'')
		vec_rm_last(expand->states);
}

static void 	handle_unset(t_expand *expand)
{
	int cnt;

	cnt = 0;
	while (cnt < N_STATES && g_state_map[cnt] != expand->raw[expand->index])
		cnt++;
	if (cnt < N_STATES)
		vec_push(expand->states, &cnt);
}

int handle_all(t_expand *expand, int (*handler)(t_expand *))
{
	int cnt;
	int error;
	t_state state;

	while (expand->index < expand->size)
	{
		if (expand->states->size)
		{
			state = (t_state)vec_get_last(expand->states);

		}
		else
		{
			cnt = 0;
			while (cnt < N_STATES && g_state_map[cnt] != expand->raw[expand->index])
				cnt++;
			if (cnt < N_STATES)
				vec_push(expand->states, &cnt);
		}
		expand->index++;
	}
	return (0);
}

static t_expand *init_expand(char *raw)
{
	t_expand *expand;

	expand = xmalloc(sizeof(t_expand));
	expand->raw = raw;
	expand->index = 0;
	expand->size = strlen(raw);
	expand->states = vec_init(N_STACK_SIZE, sizeof(t_state));
	return (expand);
}

int expand_raw(char **raw, int (*handler)(t_expand *))
{
	t_expand *expand;
	int error;

	if (!raw || !*raw || !**raw)
		return (E_NULL_INPUT);
	error = 0;
	expand = init_expand(*raw);

	if (!error && expand->states->size)
		error = E_INCOMPLETE_INPUT;
	*raw = expand->raw;
	free(expand);
	return (error);
}