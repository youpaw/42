/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type_to_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:52:34 by dbutterw          #+#    #+#             */
/*   Updated: 2020/11/12 19:11:12 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

const char	*token_type_to_string(t_token_type t)
{
	static const char *token_types_map[N_TOKEN_TYPES] = {
			"and_if",
			"or_if",
			"double_less",
			"double_great",
			"less_and",
			"great_and",
			"and",
			"or",
			"less",
			"great",
			"semi",
			"newline",
			"bang",
			"io number",
			"assignment word",
			"command name",
			"filename",
			"here end",
			"word"
	};

	return (token_types_map[t]);
}
