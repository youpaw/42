/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_dollar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:54:42 by fmallist          #+#    #+#             */
/*   Updated: 2020/11/10 15:59:49 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "expand.h"
#include "cc_str.h"
#include "cc_regex.h"

static int			handle_brace_expand(t_lexer *lexer, t_brace brace)
{
	size_t	index;
	char	*sub;
	int		error;

	index = lexer->index + 1;
	lexer->stage = l_vld;
	match_brace(lexer, brace);
	lexer->stage = l_exp;
	sub = strsub(lexer->raw, index, lexer->index - index - 1);
	error = 0;
	if (brace == l_figure_brace)
		error = expand_parameter(&sub);
	else if (brace == l_round_brace)
	{
		if (match(sub, "(*)"))
			error = expand_calc(&sub);
	}
	else if (brace == l_square_brace)
		error = expand_calc(&sub);
	if (!error)
		strjoin_expanded(lexer, index, sub, 2);
	if (sub)
		free(sub);
	return (error);
}

static void			handle_field_expand(t_lexer *lexer)
{
	size_t	index;
	char	*sub;

	index = lexer->index;
	match_parameter(lexer);
	if (index == lexer->index)
		return ;
	sub = strsub(lexer->raw, index, lexer->index - index);
	if (*sub == '?')
		expand_exit_code(&sub);
	else if (*sub)
		expand_parameter(&sub);
	strjoin_expanded(lexer, index, sub, 1);
	free(sub);
}

int					exp_dollar(t_lexer *lexer)
{
	t_brace	brace;
	int		error;

	error = 0;
	if (get_brace(lexer->raw + lexer->index, &brace) > 0)
		error = handle_brace_expand(lexer, brace);
	else
		handle_field_expand(lexer);
	vec_rm_last(lexer->slices);
	return (error);
}
