/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:13:11 by mgena             #+#    #+#             */
/*   Updated: 2020/11/15 19:19:19 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	(*g_handlers[N_LEX_STAGES][N_STATES + 1])(t_lexer *) = {
	{
		&vld_back_slash, &tok_single_quote, &tok_double_quote, &tok_dollar,
		&tok_bang, NULL, &tok_unset
	},
	{
		&vld_back_slash, &tok_single_quote, &tok_double_quote, &tok_dollar,
		&vld_bang, &vld_heredoc, &tok_unset
	},
	{
		&exp_back_slash, &exp_single_quote, &exp_double_quote,
		&exp_dollar, NULL, NULL, &exp_unset
	}
};

int		lex_map(t_lexer *lexer, t_state current)
{
	if (*g_handlers[lexer->stage][current])
		return ((*g_handlers[lexer->stage][current])(lexer));
	else
		vec_rm_last(lexer->slices);
	return (0);
}
