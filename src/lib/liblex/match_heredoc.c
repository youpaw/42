/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/15 18:24:38 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "cc_str.h"

static char	*join_end(char *end)
{
	char *ar[4];

	ar[0] = "\n";
	ar[1] = end;
	ar[2] = "\n";
	ar[3] = NULL;
	return (strnjoin((const char **)ar));
}

static int	match_end(t_lexer *lexer, t_token *token, size_t start_token_index)
{
	int		error;
	char	*end;
	char	*fnd;
	size_t	sp_len;
	size_t	sub_len;

	error = E_INCINP;
	end = join_end(token->raw);
	if (!(fnd = strstr(lexer->raw + lexer->index, end)))
		fnd = strchr(lexer->raw + lexer->index, '\4');
	if (fnd)
	{
		vec_rm_at(lexer->tokens, start_token_index);
		sub_len = fnd - (lexer->raw + lexer->index);
		sub_len += *fnd == '\4' ? 0 : 1;
		token->raw = strsub(lexer->raw, lexer->index, sub_len);
		token->type = l_here_end;
		vec_push_at(lexer->tokens, token, start_token_index);
		sp_len = *fnd == '\4' ? 1 : strlen(end);
		strcpy(lexer->raw + lexer->index, fnd + sp_len);
		lexer->size = strlen(lexer->raw);
		error = 0;
	}
	free(end);
	return (error);
}

int			match_heredoc(t_lexer *lexer)
{
	t_slice slice;
	t_token token;
	int		error;

	vec_get_last(&slice, lexer->slices);
	if (slice.state == l_heredoc && lexer->raw[lexer->index] == '\n')
		lexer->index++;
	else
		return (0);
	while (slice.state == l_heredoc)
	{
		vec_get_at(&token, lexer->tokens, slice.index);
		if ((error = match_end(lexer, &token, slice.index)))
			break ;
		vec_rm_last(lexer->slices);
		vec_get_last(&slice, lexer->slices);
	}
	return (error);
}
