//
// Created by youpaw on 9/28/20.
//

#include "calc.h"
#include "error.h"

int 	calc_state_operator(t_calc *calc)
{
	if (calc_get_operator(calc) && calc_get_number(calc))
		return (E_OPEXPEC);
	return (0);
}