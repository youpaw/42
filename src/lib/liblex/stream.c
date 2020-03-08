#include "lexer_internal.h"

int	is_eos(t_stream *s)
{
	return (*s->raw == 0);
}

void	advance(t_stream *s)
{
	if (is_eos(s))
	{
		fdputs("unexpected eos\n", STDERR_FILENO);
		exit(3);
	}
	s->raw++;
}

char	get_current_char(t_stream *s)
{
	return (*s->raw);
}

void	clear_token(t_stream *s)
{
	memset(s->current_token, 0, strlen(s->current_token));
}

void	append_char_to_token(t_stream *s)
{
	str_append_char(s->current_token, get_current_char(s));
}

void	append_custom_char_to_token(t_stream *s, char c)
{
	str_append_char(s->current_token, c);
	str_append_char(s->current_token, 0);
}

void	set_token(t_stream *s, char *new)
{
	strcpy(s->current_token, new);
	s->current_token[strlen(new)] = 0;
}

char *get_token(t_stream *s)
{
	return (s->current_token);
}

int		is_error(t_stream *s)
{
	return (get_error(s) != E_OK);
}

void	set_error(t_stream *s, int error)
{
	s->error = error;
}

int		get_error(t_stream *s)
{
	return (s->error);
}