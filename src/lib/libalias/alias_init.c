/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <azomega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:15 by azomega           #+#    #+#             */
/*   Updated: 2020/11/14 15:11:11 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alias.h"
#include "cc_str.h"

t_hash_map *g_aliases;

void		alias_init(void)
{
	g_aliases = hash_map_new(N_MAX_ALIAS, (size_t (*)(const void *)) &strhash, \
		(int (*)(const void *, const void *)) &alias_cmp_pair, &alias_del_pair);
}
