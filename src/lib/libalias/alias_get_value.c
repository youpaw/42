/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias_get_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:00:13 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:00:16 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alias.h"
#include "cc_hash_map.h"

const char	*alias_get_value(const char *key)
{
	return (hash_map_get_val(g_aliases, key));
}
