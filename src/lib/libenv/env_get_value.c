/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:04:11 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:04:13 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "cc_hash_map.h"

const char	*env_get_value(const char *key)
{
	const char *value;

	if (!(value = hash_map_get_val(g_env, key)))
		return (hash_map_get_val(g_inter_env, key));
	return (value);
}
