//
// Created by youpaw on 9/29/20.
//

#include "calc.h"
#include "cc_str.h"

static void convert_paranthesis(t_vec *postfix, t_vec *stack, \
								t_calc_token *token)
{
	t_calc_token tmp;

	if (!strcmp(token->raw, "("))
		vec_push(stack, token);
	else
	{
		vec_pop(&tmp, stack);
		while (strcmp(tmp.raw, "("))
		{
			vec_push(postfix, &tmp);
			vec_pop(&tmp, stack);
		}
	}
}

static void convert_operators(t_vec *postfix, t_vec *stack, \
								t_calc_token *token)
{
	t_calc_token tmp;

	vec_pop(&tmp, stack);
	while (calc_is_operator(tmp.type) && tmp.priority >= token->priority)
	{
		vec_push(postfix, &tmp);
		vec_pop(&tmp, stack);
	}
	vec_push(stack, &tmp);
	vec_push(stack, token);
}

t_vec	*calc_convert_to_postfix(t_vec *tokens)
{
	size_t index;
	t_vec *stack;
	t_vec *postfix;
	t_calc_token token;

	index = 0;
	stack = vec_new(CALC_VEC_CAPACITY, sizeof(t_calc_token), NULL);
	postfix = vec_new(CALC_VEC_CAPACITY, sizeof(t_calc_token), NULL);
	while(index < tokens->size)
	{
		vec_get_at(&token, tokens, index);
		if(token.type == c_parenthesis)
			convert_paranthesis(postfix, stack, &token);
		else if(token.type == c_number)
			vec_push(postfix, &token);
		else
			convert_operators(postfix, stack, &token);
		index++;
	}
	vec_del(&stack);
	return (postfix);
}