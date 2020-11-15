/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:59:48 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 21:59:52 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_hash_map.h"
#include "cc_str.h"
#include "cc_char.h"
#include "alias.h"

static int	is_char_valid(char c)
{
	return (c != '\\' && c != '=' && c != '/');
}

size_t		get_valid_alias_name_len(const char *name)
{
	size_t index;

	index = 0;
	while (name[index] && is_char_valid(name[index]))
		index++;
	if (name[index] != '=')
		return (0);
	return (index);
}

int			alias_add(const char *field)
{
	t_hash_pair	pair;
	size_t		name_len;

	if (!field || !(name_len = get_valid_alias_name_len(field)))
		return (1);
	pair.key = strsub(field, 0, name_len);
	pair.value = strdup(field + name_len + 1);
	return (hash_map_insert(g_aliases, &pair));
}
