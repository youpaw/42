//
// Created by youpaw on 10/3/20.
//

#include "calc.h"

int 	calc_operate_mod(t_calc_eval *a, t_calc_eval *b)
{
	if (!a->val)
		return (1);
	b->val = b->val % a->val;
	return (0);
}
