#include "lexer.h"
#include "lexer_internal.h"

static t_tlist *g_tokens = NULL;
static t_list *g_current = NULL;
static t_stream *g_stream = NULL;


void	add_token(char *raw, t_token_type type)
{
	t_list *new;
	t_token *t;

	t = (t_token *)xmalloc(sizeof(t_token));
	strcpy(t->raw, raw);
	t->type = type;

	memset(raw, 0, strlen(raw));

	new = xmalloc(sizeof(t_list));
	new->content = t;

	if (g_current != NULL)
	{
		g_current->next = new;
	}
	else
	{
		g_tokens->tokens = new;
	}
	g_current = new;
}

int		append_c2t()
{
	append_char_to_token(g_stream);
	return 1;
}

void	loop_body()
{
	int	b;

	b = 1;
	try_operator(g_stream, &b) || try_quote(g_stream, &b) || append_c2t();
	//if (b)
	//{
	//	;
	if (!is_eos(g_stream))
	{
		advance(g_stream);
	}
		
	//}
	
}

void	main_loop()
{

	while (!is_eos(g_stream) && !is_error(g_stream))
	{
		loop_body();
	}
	if (is_error(g_stream))
	{
		return;
	}
	if (get_token(g_stream)[0] != 0)
	{
		//int b;
		//int	r = try_operator(g_stream, &b);
		//if (!r)
		//{
		//	g_tokens->error = E_UNDEFINED_TOKEN;
		//	add_token(get_token(g_stream), l_undefined);
		//}

		add_token(get_token(g_stream), l_word);
	}
}

void	tokenize_string(t_tlist *tokens, const char *string)
{
	if (g_tokens != NULL)
	{
		fdputs("previous tokenize_string did not finish\n", STDERR_FILENO);
		exit(2);
	}
	g_tokens = tokens;
	g_stream = xmalloc(sizeof(t_stream));
	g_stream->raw = (char *)string;
	g_stream->current_token = strnew(strlen(string));
	g_stream->error = E_OK;
	main_loop();
	tokens->error = g_stream->error;
	g_tokens = NULL;
	g_current = NULL;
	//free(g_stream->raw);
	free(g_stream->current_token);
	free(g_stream);
}
