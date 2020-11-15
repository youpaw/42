/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:54:42 by fmallist          #+#    #+#             */
/*   Updated: 2020/11/10 15:59:49 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "cc_mem.h"
#include "cc_str.h"

t_tokens	*get_tokens(t_lexer *lexer, int error)
{
	t_tokens	*tokens;
	size_t		index;

	tokens = xmalloc(sizeof(t_tokens));
	lexer->raw[lexer->size - 1] = '\0';
	tokens->raw = strdup(lexer->raw);
	tokens->size = lexer->tokens->size;
	tokens->tokens = xmalloc(sizeof(t_token *) * tokens->size);
	tokens->index = 0;
	tokens->error = error;
	index = 0;
	while (index < tokens->size)
	{
		tokens->tokens[index] = xmalloc(sizeof(t_token));
		vec_get_at(tokens->tokens[index], lexer->tokens, index);
		index++;
	}
	free(lexer->tokens->data);
	free(lexer->tokens);
	lexer->tokens = NULL;
	return (tokens);
}
