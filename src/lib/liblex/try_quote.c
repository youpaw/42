#include "lexer_internal.h"

int	is_quote(char c)
{
	return (c == '\'' || c == '"');
}

int	process_escape(t_stream *s, int *need_advance)
{
	advance(s);
	if (is_eos(s))
	{
		append_custom_char_to_token(s, '\\');
		return (1);
	}
	if (get_current_char(s)=='n')
	{
		if (get_token(s)[0] != 0)
		{
			add_token(get_token(s), l_word);
		}
		strcpy(s->current_token, "\\n");
		add_token(get_token(s), l_newline);
		return (1);
	}
	//append_char_to_token(s);
	return (0);
}

int	try_quote(t_stream *s, int *b)
{
	if (get_current_char(s) == '\\')
	{
		return (process_escape(s, b));
	}
	return (0);
}
