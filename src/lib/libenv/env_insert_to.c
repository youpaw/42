/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_insert_to.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:04:21 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:04:23 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_hash_map.h"
#include "cc_str.h"
#include "env.h"

int	env_insert_to(t_hash_map *hm, const char *field)
{
	t_hash_pair	pair;
	size_t		name_len;

	if (!hm || !field || !(name_len = get_valid_name_length(field)))
		return (1);
	pair.key = strsub(field, 0, name_len);
	pair.value = strdup(field + name_len + 1);
	return (hash_map_insert(hm, &pair));
}
