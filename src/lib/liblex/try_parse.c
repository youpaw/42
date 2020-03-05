#include "lexer.h"
#include "lexer_internal.h"

int		try_parse_type(const char *t, t_token_type *type)
{
	if (strlen(t) == 1)
	{
		return (try_one(t, type));
	}
	return (try_other(t, type));
}

int		try_one(const char *t, t_token_type *type)
{
	if (*t == '\n')
	{
		*type = l_newline;
		return (1);
	}
	if (*t == '{')
	{
		*type = l_left_brace;
		return (1);
	}
	if (*t == '}')
	{
		*type = l_right_brace;
		return (1);
	}
	if (*t == '!')
	{
		*type = l_bang;
		return (1);
	}

	return (0);
}

int		try_other(const char *t, t_token_type *type)
{
	if (str_equals(t, "&&"))
	{
		*type = l_and_if;
		return (1);
	}
	if (str_equals(t, ">|"))
	{
		*type = l_clobber;
		return (1);
	}
	if (str_equals(t, ">>"))
	{
		*type = l_double_great;
		return (1);
	}
	if (str_equals(t, "<<"))
	{
		*type = l_double_less;
		return (1);
	}
	if (str_equals(t, "<<-"))
	{
		*type = l_double_less_dash;
		return (1);
	}
	if (str_equals(t, ";;"))
	{
		*type = l_double_semi;
		return (1);
	}
	if (str_equals(t, ">&"))
	{
		*type = l_great_and;
		return (1);
	}
	if (str_equals(t, "<&"))
	{
		*type = l_less_and;
		return (1);
	}
	if (str_equals(t, "||"))
	{
		*type = l_or_if;
		return (1);
	}
	return (0);
}
