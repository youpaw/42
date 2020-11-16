/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_get_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by hlorrine          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

static t_hash_bin_pair	*get_bin_pair(const char *bin)
{
	return (hash_map_get_val(g_hash, bin));
}

const char				*hash_get_path(const char *bin)
{
	t_hash_bin_pair	*bin_pair;
	char			*path;

	if ((bin_pair = get_bin_pair(bin)) && ++(bin_pair->count))
		return (bin_pair->path);
	if (!(path = hash_get_bin_path(bin)))
		return (NULL);
	hash_insert(bin, path);
	free(path);
	return (hash_get_path(bin));
}
