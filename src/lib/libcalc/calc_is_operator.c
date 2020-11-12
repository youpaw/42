//
// Created by youpaw on 10/2/20.
//
#include "calc.h"

int	calc_is_operator(t_calc_type type)
{
	if (type < N_OPERATORS)
		return (1);
	return (0);
}
