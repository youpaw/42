//
// Created by youpaw on 9/28/20.
//

#include "calc.h"
#include "error.h"
#include "cc_num.h"
#include "cc_str.h"

static void handle_operand(t_vec *stack, t_calc_token *token)
{
	t_calc_eval eval;

	eval.val = atoi(token->raw);
	eval.type = token->type;
	vec_push(stack, &eval);
}

static int handle_operator(t_vec *stack, t_calc_token *token)
{
	return (calc_operate(stack, token));
}

static void get_result(char **raw, t_vec *stack)
{
	t_calc_eval result;

	vec_pop(&result, stack);
	free(*raw);
	*raw = itoa(result.val);
}

static void print_eval_error(char *raw)
{
	const char *arg[2];
	size_t last_index;

	raw++;
	last_index = strlen(raw) - 1;
	raw[last_index] = '\0';
	arg[0] = raw;
	arg[1] = "0";
	error_print(E_ZERODIV, arg);
}

int	calc_evaluate(char **raw, t_vec *postfix)
{
	size_t index;
	t_vec *stack;
	t_calc_token token;
	int error;

	index = 0;
	error = 0;
	stack = vec_new(CALC_VEC_CAPACITY, sizeof(t_calc_eval), NULL);
	while (index < postfix->size)
	{
		vec_get_at(&token, postfix, index);
		if (calc_is_operator(token.type))
		{
			if ((error = handle_operator(stack, &token)))
				break ;
		}
		else
			handle_operand(stack, &token);
		index++;
	}
	error ? print_eval_error(*raw) : get_result(raw, stack);
	vec_del(&stack);
	return (error);
}