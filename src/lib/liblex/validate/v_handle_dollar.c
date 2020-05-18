//
// Created by youpaw on 13.05.2020.
//

#include "lex_validate.h"
#include "vector/cc_vec.h"

static void init_dollar(t_validate *validate, t_state *cpy)
{
	*cpy = validate->state;
	validate->state = l_unset;
	validate->expanding = 1;
	validate->index+=2;
}

static void match_brace(t_validate *validate, t_brace *brace, t_vec *stack)
{
	t_brace old;
	int code;

	old = *brace;
	code = get_brace(validate->raw[validate->index], brace);
	if (code == 0)
		return ;
	validate->index++;
	if (*brace != old)
		return ;
	if (code == 1)
		vec_push(stack, brace);
	else
	{
		vec_rm_last(stack);
		if (stack->size)
			*brace = (t_brace)vec_get_last(stack);
	}
}

int 	v_handle_dollar(t_validate *validate)
{
	t_state cpy;
	t_vec *stack;
	t_brace brace;
	int error;

	if (get_brace(validate->raw[validate->index + 1], &brace) <= 0)
		return (E_OK);
	init_dollar(validate, &cpy);
	stack = vec_init(N_STACK_SIZE, sizeof(t_brace));
	vec_push(stack, &brace);
	error = 0;
	while (validate->index < validate->size && stack->size)
	{
		if (validate->state == l_unset)
			match_brace(validate, &brace, stack);
		if ((error = g_validate_map[validate->state].handler(validate)))
			break ;
		validate->index++;
	}
	if (!error && (validate->state != l_unset || stack->size))
		error = E_INCOMPLETE_INPUT;
	vec_del(&stack);
	validate->state = cpy;
	validate->expanding = 0;
	return (error);
}