/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vld_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:52:34 by dbutterw          #+#    #+#             */
/*   Updated: 2020/11/12 19:11:12 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "cc_str.h"

static int	get_end(t_vec *tokens, size_t start_token_index, t_token *end)
{
	const char	*arr[1];

	vec_get_at(end, tokens, start_token_index);
	if (end->type != l_filename)
	{
		if (end->type == l_newline)
			arr[0] = token_type_to_string(l_newline);
		else
			arr[0] = end->raw;
		error_print(E_UNEXPTOK, (const char **)arr);
		return (E_UNEXPTOK);
	}
	return (0);
}

static int	tokenize_end(t_lexer *lexer)
{
	int		error;
	t_state	current;
	t_slice	slice;
	size_t	slice_index;

	error = 0;
	slice.index = lexer->index;
	slice.state = l_unset;
	slice_index = lexer->slices->size;
	vec_push(lexer->slices, &slice);
	while (lexer->index < lexer->size)
	{
		current = get_current_state(lexer);
		if ((error = lex_map(lexer, current)) != E_OK)
			break ;
		if (lexer->raw[lexer->index] == '\n')
			break ;
		lexer->index++;
	}
	if (error == E_HEREDOC)
		error = 0;
	if (!error && lexer->index >= lexer->size - 1)
		error = E_INCINP;
	vec_rm_at(lexer->slices, slice_index);
	return (error);
}

int			vld_heredoc(t_lexer *lexer)
{
	t_slice slice;
	size_t	slice_index;
	t_token	end;
	size_t	start_token_index;
	int		error;

	slice_index = lexer->slices->size - 1;
	start_token_index = lexer->tokens->size;
	error = tokenize_end(lexer);
	if (!error && !(error = get_end(lexer->tokens, start_token_index, &end)))
	{
		vec_rm_at(lexer->slices, slice_index);
		slice.index = start_token_index;
		slice.state = l_heredoc;
		vec_push(lexer->slices, &slice);
	}
	if (!error)
		error = E_HEREDOC;
	return (error);
}
