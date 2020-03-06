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

int	process_single_quote(t_stream *s)
{
	advance(s);
	while(get_current_char(s) != '\'' && !is_eos(s))
	{
		append_char_to_token(s);
		advance(s);
	}
	if(get_current_char(s) != '\'')
	{
		set_error(s, E_MISSING_SECOND_SINGLE_QUOTE);
		return (1);
	}
	else
	{
		advance(s);
		return (0);
	}
}

int	try_quote(t_stream *s, int *b)
{
	if (get_current_char(s) == '\\')
	{
		return (process_escape(s, b));
	}
	if (get_current_char(s) == '\'')
	{
		return (process_single_quote(s));
	}
	return (0);
}
