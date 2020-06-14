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
		expand->state = e_unset;
}

static void 	handle_unset(t_expand *expand)
{
	int cnt;

	cnt = 0;
	while (cnt < N_STATES && g_state_map[cnt] != expand->raw[expand->index])
		cnt++;
	expand->state = cnt;
}

static t_expand *init_expand(char *raw)
{
	t_expand *expand;

	expand = xmalloc(sizeof(t_expand));
	expand->raw = raw;
	expand->flags = 0;
	expand->index = 0;
	expand->size = strlen(raw);
	expand->state = e_unset;
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
	while (expand->index < expand->size)
	{
		if (expand->state == e_single_quote)
			handle_single_quote(expand);
		else if (expand->state == e_unset)
			handle_unset(expand);
		else if ((error = handler(expand)))
			break ;
		expand->index++;
	}
	if (!error && expand->state != e_unset)
		error = E_INCOMPLETE_INPUT;
	*raw = expand->raw;
	free(expand);
	return (error);
}