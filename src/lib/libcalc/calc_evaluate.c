//
// Created by youpaw on 9/28/20.
//

#include "calc.h"
#include "cc_num.h"
#include "cc_str.h"

static void handle_operand(t_vec *stack, t_calc_token *token)
{
	t_calc_eval eval;

	eval.val = atoi(token->raw);
	eval.type = token->type;
	vec_push(stack, &eval);
}

static int handle_operator(t_vec **stack, t_calc_token *token)
{
	if (calc_operate(*stack, token))
	{
		vec_del(stack);
		return (1);
	}
	return (0);
}

static void get_result(char **raw, t_vec **stack)
{
	t_calc_eval result;

	vec_pop(&result, *stack);
	*raw = itoa(result.val);
	vec_del(stack);
}

int	calc_evaluate(char **raw, t_vec *postfix)
{
	size_t index;
	t_vec *stack;
	t_calc_token token;

	index = 0;
	stack = vec_new(CALC_VEC_CAPACITY, sizeof(t_calc_eval), NULL);
	while (index < postfix->size)
	{
		vec_get_at(&token, postfix, index);
		if (calc_is_operator(token.type))
		{
			if (handle_operator(&stack, &token))
				return (1);
		}
		else
			handle_operand(stack, &token);
		index++;
	}
	get_result(raw, &stack);
	return (0);
}