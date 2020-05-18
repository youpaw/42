//
// Created by youpaw on 11.05.2020.
//

#include "lex_validate.h"
#include "string/cc_str.h"

int 	v_handle_bs(t_validate *validate)
{
	char c;

	c = validate->raw[validate->index];
	if (!validate->expanding && c == '\n')
	{
		if (validate->index == validate->size - 1)
			return (E_INCOMPLETE_INPUT);
		strcpy(validate->raw + validate->index - 1, \
		validate->raw + validate->index + 1);
		validate->index -= 2;
		validate->size -= 2;
	}
	validate->state = l_unset;
	return (E_OK);
}