//
// Created by youpaw on 9/28/20.
//

#include "calc.h"
#include "cc_str.h"

static const char *operator_map(int index)
{
	static const char *operators[N_OPERATORS] = {
			"-", "+", "*", "/", "%","-", "+", ">", "<", ">=", "<=", "==",
			"!=", "&&", "||"};

	if (index >= 0 && index < N_OPERATORS)
		return (operators[index]);
	return (NULL);
}

static int 	change_state(t_calc_type type, t_calc *calc)
{
	if (type >= N_OPERATORS)
		return (1);
	if (calc->state == c_st_operator && calc_is_binary(type))
			return (1);
	calc->state = c_st_operator;
	return (0);
}

int 	calc_get_operator(t_calc *calc)
{
	t_calc_token token;
	const char *op;
	int cnt;

	cnt = 0;
	while ((op = operator_map(cnt)) && \
	strncmp(calc->raw + calc->index, op, strlen(op)))
		cnt++;
	if (calc_is_unary(cnt) && calc->state == c_st_number)
			cnt = cnt == c_negative ? c_subtraction : c_addition;
	if (change_state(cnt, calc))
		return (1);
	token.raw = strdup(op);
	token.type = (t_calc_type)cnt;
	token.priority = calc_get_priority(token.type);
	vec_push(calc->tokens, &token);
	calc->index += strlen(token.raw) - 1;
	return (0);
}