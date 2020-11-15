/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vld_bang.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:52:34 by dbutterw          #+#    #+#             */
/*   Updated: 2020/11/12 19:11:12 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "cc_str.h"
#include "expand.h"

static void		handle_error(const char *str)
{
	const char	*args[1];

	args[0] = str;
	error_print(E_NOEVENT, args);
}

int				vld_bang(t_lexer *lexer)
{
	char	*expand;
	size_t	index;

	index = lexer->index;
	if (match_bang(lexer))
	{
		lexer->index--;
		vec_rm_last(lexer->slices);
		return (E_OK);
	}
	expand = strsub(lexer->raw, index, lexer->index - index);
	if (expand_bang(&expand))
	{
		handle_error(expand);
		free(expand);
		return (E_NOEVENT);
	}
	strjoin_expanded(lexer, index, expand, 1);
	free(expand);
	lexer->flags[l_print_command] = 1;
	vec_rm_last(lexer->slices);
	return (E_OK);
}
