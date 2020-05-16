//
// Created by youpaw on 12.05.2020.
//

#include "lex_validate.h"

int		v_handle_us(t_validate *validate)
{
	int cnt;
	char c;

	c = validate->raw[validate->index];
	if (c == '!')
		return (v_handle_bang(validate));
	if (c == '$')
		return (v_handle_dollar(validate));
	cnt = 0;
	while (cnt < (N_STATES - 1) && g_validate_map[cnt].raw != c)
		cnt++;
	validate->state = g_validate_map[cnt].state;
	return (E_OK);
}