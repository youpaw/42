//Created by Darth Butterwell on 8/16/20.
//

#include "calc.h"
#include "cc_str.h"

static void calc_vec_del(void *token)
{
	free(((t_calc_token *)token)->raw);
}

static void calc_init(t_calc *calc, char *raw)
{
	calc->raw = strdup(raw);
	calc->index = 0;
	calc->size = strlen(raw);
	calc->state = c_st_operator;
	calc->tokens = vec_new(CALC_VEC_CAPACITY, sizeof(t_calc_token), \
	&calc_vec_del);
}

static void calc_destruct(t_calc *calc)
{
	free(calc->raw);
	vec_del(&calc->tokens);
}

int	calc(char **raw)
{
	t_calc	calc;
	t_vec	*postfix;
	int		error;

	if (strlen(*raw) == 2)
	{
		free(*raw);
		*raw = strdup("0");
		return (0);
	}
	calc_init(&calc, *raw);
	if (!(error = calc_tokenize(&calc)))
	{
		postfix = calc_convert_to_postfix(calc.tokens);
		error = calc_evaluate(raw, postfix);
		vec_del(&postfix);
	}
	calc_destruct(&calc);
	return (error);
}
