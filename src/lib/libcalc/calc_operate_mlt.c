//
// Created by youpaw on 10/3/20.
//

#include "calc.h"

int	calc_operate_mlt(t_calc_eval *a, t_calc_eval *b)
{
	b->val = b->val * a->val;
	return (0);
}
