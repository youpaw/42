/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_back_slash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:52:34 by dbutterw          #+#    #+#             */
/*   Updated: 2020/11/12 19:11:12 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "cc_mem.h"

int		exp_back_slash(t_lexer *lexer)
{
	memmove(lexer->raw + lexer->index - 1, lexer->raw + lexer->index,
		lexer->size - lexer->index + 1);
	lexer->index--;
	lexer->size--;
	vec_rm_last(lexer->slices);
	return (E_OK);
}
