//
// Created by youpaw on 9/28/20.
//
#include "calc.h"
#include "error.h"

int 	calc_state_number(t_calc *calc)
{
	if (calc_get_operator(calc))
	{
		if (calc_is_forbidden(calc->raw[calc->index]))
			return (E_INVAOP);
		return (E_INVEXP);
	}
	return (0);
}