#include "lexer.h"
#include "lexer_internal.h"

void	free_token(t_token *t)
{
	//free(t->raw);
	free(t);
}

void		destruct_tlist(t_tlist *tokens)
{
	t_list *n;
	t_list *next;
	if (tokens->raw != NULL)
	{
		free(tokens->raw);
	}
	n = tokens->tokens;
	while (n != NULL)
	{
		next = n->next;
		free_token((t_token *)n->content);
		n = next;
	}
}

int		recognize_number(t_token *t)
{
	if (isnumber(t->raw))
	{
		t->type = l_io_number;
		return (1);
	}
	return (0);
}

void	recognize(t_token *t)
{
	if (t->type == l_word)
	{
		try_parse_type(t->raw, &t->type) 
		|| recognize_number(t);
		if (t->type == l_undefined)
		{
			t->type = l_word;
		}
	}
}

t_tlist *recognize_tokens(t_tlist *tokens)
{
	t_list *n;

	n = tokens->tokens;
	while (n != NULL)
	{
		recognize((t_token*)n->content);
		n = n->next;
	}


	return (tokens);
}

t_tlist *tokenize(const char *string)
{
	t_tlist *tokens;

	tokens = malloc(sizeof(t_tlist));
	tokens->error = 0;
	tokens->tokens = NULL;
	if (string == NULL)
	{
		tokens->raw = NULL;
		tokens->error = E_NULL_INPUT;
		return (tokens);
	}
	tokens->raw = strdup(string);
	tokenize_string(tokens, string);
	return (recognize_tokens(tokens));
}

void	copy_token(t_token *dst, t_token *src)
{
	strcpy(dst->raw, src->raw);
	dst->type = src->type;
}

void	copy_tokens(t_token *dst, t_list *n)
{
	while (n != NULL)
	{
		//dst = (t_token *)malloc(sizeof(t_token));
		copy_token(dst, (t_token *)n->content);
		n = n->next;
		dst++;
	}
}

t_tokens *to_tokens(t_tlist *tlist)
{
	t_tokens *tokens;

	tokens = (t_tokens *)xmalloc(sizeof(t_tokens));
	tokens->error = tlist->error;
	tokens->raw =tlist->raw == NULL ? NULL : strdup(tlist->raw);
	tokens->size = lst_count(tlist->tokens);
	tokens->tokens = tokens->size == 0 ? NULL : (t_token *)xmalloc(sizeof(t_token) * tokens->size);
	copy_tokens(tokens->tokens, tlist->tokens);
	return (tokens);
}