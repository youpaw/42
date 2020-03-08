#include "lexer_internal.h"

int	is_quote(char c)
{
	return (c == '\'' || c == '"');
}

int	get_missing_second_quote_error(char quote)
{
	if (quote == '\'')
	{
		return (E_MISSING_SECOND_SINGLE_QUOTE);
	}
	if (quote == '"')
	{
		return (E_MISSING_SECOND_DOUBLE_QUOTE);
	}
	if (quote == '`')
	{
		return (E_MISSING_SECOND_BACK_QUOTE);
	}
	fdputs("unexpected quote\n", STDERR_FILENO);
	exit(5);
}

int	process_escape(t_stream *s)
{
	advance(s);
	if (is_eos(s))
	{
		append_custom_char_to_token(s, '\\');
		return (1);
	}
	if (get_current_char(s) == 'n')
	{
		if (get_token(s)[0] != 0)
		{
			add_token(get_token(s), l_word);
		}
		strcpy(s->current_token, "\\n");
		add_token(get_token(s), l_newline);
		return (1);
	}
	append_char_to_token(s);
	return (1);
}

int	process_escape_in_dquote(t_stream *s)
{

	advance(s);
	//	/$	token += $; return 1
	if (!is_eos(s) && str_contains_char("$\\\"`", get_current_char(s)))
	{
		//append_char_to_token(s);
		return (0);
	}

	append_custom_char_to_token(s, '\\');
	//	/	token += /; return 1
	if (is_eos(s))
	{
		return (1);
	}
	//	/"	token += /; return 1
	if (get_current_char(s) == '"')
	{
		return (1);
	}
	//	/?	token += /?; return 1;
	//append_char_to_token(s);
	return (0);
}

int	process_back_quote_inside_double_quote(t_stream *s)
{
	append_char_to_token(s);
	advance(s);
	while (!is_eos(s) && get_current_char(s) != '`')
	{
		append_char_to_token(s);
		advance(s);
	}

	if (is_eos(s))
	{
		set_error(s, E_MISSING_SECOND_BACK_QUOTE);
		return (1);
	}
	append_char_to_token(s);
	advance(s);

	return (1);

}

int	process_special(t_stream *s, char quote)
{
	if (quote != '"')
	{
		return (0);
	}
	if (get_current_char(s) == '\\')
	{
		return (process_escape_in_dquote(s));
	}
	if (get_current_char(s) == '`')
	{
		return (process_back_quote_inside_double_quote(s));
	}
	return (0);
}

int	process_quote(t_stream *s, char quote)
{
	advance(s);
	while (get_current_char(s) != quote && !is_eos(s))
	{
		if (!process_special(s, quote))
		{
			append_char_to_token(s);
			advance(s);
		}
		if (is_error(s))
		{
			return (1);
		}
		if (is_eos(s))
		{
			set_error(s, get_missing_second_quote_error(quote));
			return (1);
		}
	}
	if (get_current_char(s) != quote)
	{
		set_error(s, get_missing_second_quote_error(quote));
		return (1);
	}
	else
	{
		advance(s);
		return (0);
	}
}

int	process_single_quote(t_stream *s)
{
	return (process_quote(s, '\''));
}

int	try_quote(t_stream *s)
{
	if (get_current_char(s) == '\\')
	{
		return (process_escape(s));
	}
	if (get_current_char(s) == '\'')
	{
		return (process_single_quote(s));
	}
	if (get_current_char(s) == '"')
	{
		return (process_quote(s, '\"'));
	}
	return (0);
}
