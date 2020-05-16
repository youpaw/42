//
// Created by youpaw on 12.05.2020.
//

#include "lex_validate.h"

int		v_handle_dq(t_validate *validate)
{
	char c;

	c = validate->raw[validate->index];
	if (c == '!')
		return (v_handle_bang(validate));
	if (c == '$')
		return (v_handle_dollar(validate));
	if (c == '\\')
		validate->index++;
	else if (c == '\"')
		validate->state = l_unset;
	return (E_OK);
}