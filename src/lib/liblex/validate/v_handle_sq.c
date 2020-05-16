//
// Created by youpaw on 11.05.2020.
//

#include "lex_validate.h"

int 	v_handle_sq(t_validate *validate)
{
	char c;

	c = validate->raw[validate->index];
	if (c == '\'')
		validate->state = l_unset;
	return (E_OK);
}