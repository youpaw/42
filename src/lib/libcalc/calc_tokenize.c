//
// Created by youpaw on 9/28/20.
//

#include "calc.h"
#include "error.h"
#include "cc_str.h"
#include "cc_char.h"

static int		push_parenthesis(t_calc *calc, char c)
{
	t_calc_token	token;

	if ((c == '(' && calc->state == c_st_number) || \
		(c == ')' && calc->state == c_st_operator))
		return (E_OPEXPEC);
	token.raw = strsub(calc->raw, calc->index, 1);
	token.type = c_parenthesis;
	token.priority = calc_get_priority(token.type);
	vec_push(calc->tokens, &token);
	return (0);
}

static void		print_tokenize_error(t_calc *calc, int error)
{
	const char	*args[2];
	char		*tmp;
	size_t		last_index;

	tmp = calc->raw + 1;
	last_index = strlen(tmp) - 1;
	tmp[last_index] = '\0';
	args[0] = tmp;
	args[1] = calc->raw + calc->index;
	error_print(error, args);
}

int				calc_tokenize(t_calc *calc)
{
	int		error;
	char	c;

	error = 0;
	while (calc->index < calc->size)
	{
		c = calc->raw[calc->index];
		if (!isspace(c))
		{
			if (c == '(' || c == ')')
				error = push_parenthesis(calc, c);
			else
				error = calc_get_token(calc);
			if (error)
			{
				print_tokenize_error(calc, error);
				break ;
			}
		}
		calc->index++;
	}
	return (error);
}
