/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_evaluate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:00:56 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:00:59 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calc.h"
#include "error.h"
#include "cc_num.h"
#include "cc_str.h"

static void			handle_operand(t_vec *stack, t_calc_token *token)
{
	t_calc_eval	eval;

	eval.val = atoi(token->raw);
	eval.type = token->type;
	vec_push(stack, &eval);
}

static int			handle_operator(t_vec *stack, t_calc_token *token)
{
	return (calc_operate(stack, token));
}

static void			get_result(char **raw, t_vec *stack)
{
	t_calc_eval	result;

	if (vec_pop(&result, stack))
		result.val = 0;
	free(*raw);
	*raw = itoa(result.val);
}

static void			print_eval_error(char *raw)
{
	const char	*arg[2];
	size_t		last_index;

	raw++;
	last_index = strlen(raw) - 1;
	raw[last_index] = '\0';
	arg[0] = raw;
	arg[1] = "0";
	error_print(E_ZERODIV, arg);
}

int					calc_evaluate(char **raw, t_vec *postfix)
{
	size_t			index;
	t_vec			*stack;
	t_calc_token	token;
	int				error;

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
