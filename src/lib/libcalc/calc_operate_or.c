//
// Created by youpaw on 10/3/20.
//

#include "calc.h"

int 	calc_operate_or(t_calc_eval *a, t_calc_eval *b)
{
	b->val = b->val || a->val ? 1 : 0;
	return (0);
}
