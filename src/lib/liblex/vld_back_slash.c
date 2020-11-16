/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vld_back_slash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by hlorrine          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "cc_mem.h"

int		vld_back_slash(t_lexer *lexer)
{
	char c;

	c = lexer->raw[lexer->index];
	if (c == '\n')
	{
		memmove(lexer->raw + lexer->index - 1,
		lexer->raw + lexer->index + 1,
		lexer->size - lexer->index);
		lexer->index -= 2;
		lexer->size -= 2;
		if (lexer->index == lexer->size - 1)
			return (E_INCINP);
	}
	vec_rm_last(lexer->slices);
	return (E_OK);
}
