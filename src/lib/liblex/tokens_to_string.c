#include "lexer_internal.h"

int		count_size(t_tokens *tokens)
{
	int	i;
	int	size;
	t_token *token;
	const int	max_type_size = 50;

	size = 0;
	i = -1;
	while (++i < tokens->size)
	{
		token = tokens->tokens + i;
		size += strlen(token->raw) + 1 + max_type_size + 10;
	}
	return (size);
}

void		to_string(char *dst, t_tokens *tokens)
{
	int			i;
	t_token		*token;
	int			len;
	char		*type;

	i = -1;
	while (++i < tokens->size)
	{
		token = tokens->tokens + i;
		strcpy(dst, "[ ");
		dst += 2;
		strcpy(dst, token->raw);
		dst += strlen(token->raw);
		strcpy(dst, " ] [ ");
		dst += 5;
		type = type_to_string(token->type);
		strcpy(dst, type);
		dst += strlen(type);
		strcpy(dst, " ]\n");
		dst += 3;
	}
	*dst = 0;
}


char *tokens_to_string(t_tokens *tokens)
{
	char *dst;

	dst = xmalloc(sizeof(char) * (count_size(tokens) + 1));
	to_string(dst, tokens);
	return (dst);
}