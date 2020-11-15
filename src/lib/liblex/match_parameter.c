/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_parameter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by hlorrine          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "env.h"
#include "cc_char.h"

int			match_parameter(t_lexer *lexer)
{
	size_t len;

	if (isdigit(lexer->raw[lexer->index]) || lexer->raw[lexer->index] == '?')
		len = 1;
	else
		len = get_valid_name_length_no_check(lexer->raw + lexer->index);
	lexer->index += len;
	if (len)
		return (0);
	return (1);
}
