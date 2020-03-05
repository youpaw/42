#include "lexer_internal.h"

int	is_still_operator(const char *t)
{
	t_token_type type;

	return (try_parse_type(t, &type) && is_operator(type));
}

int	try_operator(t_stream *s, int *b)
{
	t_token_type type;
	char	*tmp;

	if (!is_still_operator(get_token(s)))
	{
		return (0);
	}
	tmp = str_append_char(strdup(get_token(s)), get_current_char(s));
	while (is_still_operator(tmp) && !is_eos(s))
	{
		append_char_to_token(s);
		advance(s);
		free(tmp);
		tmp = str_append_char(strdup(get_token(s)), get_current_char(s));
	}
	free(tmp);
	try_parse_type(get_token(s), &type);
	add_token(get_token(s), type);

	return (is_eos(s));
}
