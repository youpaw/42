/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_suffix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:52:34 by dbutterw          #+#    #+#             */
/*   Updated: 2020/11/12 19:11:12 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"
#include "cc_str.h"

char	*expand_suffix(const char *name, const char *pattern)
{
	const char	*value;
	size_t		pat_len;
	size_t		val_len;

	if (!(value = get_env_or_av_value(name)))
		return (strnew(0));
	val_len = strlen(value);
	pat_len = strlen(pattern);
	if (val_len >= pat_len && !strcmp(&value[val_len - pat_len], pattern))
		return (strsub(value, 0, val_len - pat_len));
	return (strdup(value));
}
