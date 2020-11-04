//
// Created by youpaw on 10/2/20.
//

#include "calc.h"

static void operate_unary(t_vec *stack, t_calc_type type)
{
	t_calc_eval num;

	vec_pop(&num, stack);
	if (type == c_negative)
	{
		num.val *= -1;
		vec_push(stack, &num);
	}
}

static int operate_binary(t_vec *stack, t_calc_type type)
{
	t_calc_eval a;
	t_calc_eval b;
	int error;
	static int (*op_map[N_BINARY_OPERATORS])(t_calc_eval *, t_calc_eval *) = {
			&calc_operate_mlt, &calc_operate_div, &calc_operate_mod, \
			&calc_operate_sub, &calc_operate_add, &calc_operate_grt, \
			&calc_operate_les, &calc_operate_goe, &calc_operate_loe, \
			&calc_operate_eql, &calc_operate_neq, &calc_operate_and, \
			&calc_operate_or
	};

	vec_pop(&a, stack);
	vec_pop(&b, stack);
	if (!(error = op_map[type - N_UNARY_OPERATORS](&a, &b)))
		vec_push(stack, &b);
	return (error);
}

int 	calc_operate(t_vec *stack, t_calc_token *token)
{
	if (calc_is_unary(token->type))
		operate_unary(stack, token->type);
	else
		return (operate_binary(stack, token->type));
	return (0);
}