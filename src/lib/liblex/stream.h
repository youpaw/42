#ifndef STREAM_H
#define STREAM_H

struct		s_stream
{
	char *raw; // здесь должен лежать в первозданном виде поток символов, который пришел на вход
	char *current_token;
	int		error;
};

typedef struct s_stream t_stream;

int		is_eos(t_stream *s);
void	advance(t_stream *s);
char	get_current_char(t_stream *s);
void	clear_token(t_stream *s);
void	append_char_to_token(t_stream *s);
void	append_custom_char_to_token(t_stream *s, char c);
char	*get_token(t_stream *s);
int		is_error(t_stream *s);
void	set_error(t_stream *s, int error);
int		get_error(t_stream *s);

#endif