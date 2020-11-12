/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:00:19 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:00:22 by hlorrine         ###   ########.fr       */
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
