//
// Created by youpaw on 10/3/20.
//

#include "calc.h"
#include "error.h"

int	calc_operate_mod(t_calc_eval *a, t_calc_eval *b)
{
	if (!a->val)
		return (E_ZERODIV);
	b->val = b->val % a->val;
	return (0);
}
