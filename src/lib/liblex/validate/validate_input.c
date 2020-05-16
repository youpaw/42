//
// Created by youpaw on 11.05.2020.
//

#include <stdlib.h>
#include "lex_validate.h"
#include "memory/cc_mem.h"
#include "string/cc_str.h"

static t_validate *init_validate(char *raw)
{
	t_validate *validate;

	validate = xmalloc(sizeof(t_validate));
	validate->raw = raw;
	validate->print_cmd = 0;
	validate->index = 0;
	validate->size = strlen(raw);
	validate->state = l_unset;
	return (validate);
}
int validate_input(char **raw)
{
	t_validate *validate;
	int error;

	if (!raw || !*raw || !**raw)
		return (E_NULL_INPUT);
	error = 0;
	validate = init_validate(*raw);
	while (validate->index < validate->size)
	{
		error = g_validate_map[validate->state].handler(validate);
		if (error)
			break ;
		validate->index++;
	}
	if (!error && validate->state != l_unset)
		error = E_INCOMPLETE_INPUT;
	*raw = validate->raw;
	if (validate->print_cmd)
		fdputs(validate->raw, 1);
	free(validate);
	return (error);
}