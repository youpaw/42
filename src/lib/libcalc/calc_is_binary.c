//
// Created by youpaw on 10/1/20.
//

#include "calc.h"

int	calc_is_binary(t_calc_type type)
{
	if (type > 1 && type < N_OPERATORS)
		return (1);
	return (0);
}
