#include "lexer_internal.h"

int	is_start_of_operator(char c)
{
	return (str_contains_char("><&|;", c));
}

int	is_still_operator(t_stream *s, const char *t)
{
	t_token_type type;

	return ((! is_eos(s) && strlen(t) == 1 && is_start_of_operator(*t)) || (try_parse_type(t, &type) && is_operator(type)));
}

int	try_operator(t_stream *s)
{
	t_token_type type;
	char	*tmp;

	if (!is_still_operator(s, get_token(s)))
	{
		return (0);
	}
	tmp = str_append_char(strdup(get_token(s)), get_current_char(s));
	while (!is_eos(s) && is_still_operator(s, tmp))
	{
		append_char_to_token(s);
		advance(s);
		free(tmp);
		tmp = str_append_char(strdup(get_token(s)), get_current_char(s));
	}
	free(tmp);
	type = l_word;
	try_parse_type(get_token(s), &type);
	add_token(get_token(s), type);

	return (is_eos(s));
}


int	handle_operator_start(t_stream *s)
{
	if (get_token(s)[0] != 0 && is_start_of_operator(get_current_char(s)))
	{
		add_token(get_token(s), l_word);
	}
	return (0);
}