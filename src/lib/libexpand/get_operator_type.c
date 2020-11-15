/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_operator_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:13:11 by mgena             #+#    #+#             */
/*   Updated: 2020/11/15 19:19:19 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"
#include "cc_str.h"

static t_param_type	get_colon_operator(char c)
{
	if (c == '-')
		return (e_param_or_word);
	if (c == '=')
		return (e_assign_param);
	if (c == '?')
		return (e_param_or_error);
	if (c == '+')
		return (e_null_or_word);
	return (e_unknown);
}

t_param_type		get_operator_type(const char *str)
{
	if (!*str)
		return (e_default);
	if (str[0] == ':')
		return (get_colon_operator(str[1]));
	if (!strncmp(str, "##", 2))
		return (e_rm_longest_prefix);
	if (!strncmp(str, "#", 1))
		return (e_rm_shortest_prefix);
	if (!strncmp(str, "%%", 2))
		return (e_rm_longest_suffix);
	if (!strncmp(str, "%", 1))
		return (e_rm_shortest_suffix);
	return (e_unknown);
}
