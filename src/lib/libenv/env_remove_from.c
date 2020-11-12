/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_remove_from.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:04:39 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:04:44 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_hash_map.h"

int		env_remove_from(t_hash_map *hm, const char *key)
{
	if (!hm || !key)
		return (1);
	return (hash_map_del_one(hm, key));
}
