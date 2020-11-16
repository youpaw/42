/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:13:11 by mgena             #+#    #+#             */
/*   Updated: 2020/11/15 19:19:19 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_hash_map.h"
#include "env.h"
#include "cc_str.h"

int		env_update(const char *field)
{
	t_hash_pair	pair;
	size_t		name_len;

	if (!field || !(name_len = get_valid_name_length(field)))
		return (1);
	pair.key = strsub(field, 0, name_len);
	pair.value = strdup(field + name_len + 1);
	if (hash_map_get_pair(g_env, pair.key))
		return (hash_map_insert(g_env, &pair));
	return (hash_map_insert(g_inter_env, &pair));
}
