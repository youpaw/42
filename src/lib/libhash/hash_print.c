
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:06:21 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:06:25 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"
#include "cc_str.h"
#include "cc_num.h"
#include "cc_char.h"

static void		hash_print_bin_pair(const t_hash_pair *pair)
{
	t_hash_bin_pair *path_count;

	if (!pair)
		return ;
	path_count = pair->value;
	if (path_count->count < 1000)
		putchar(' ');
	if (path_count->count < 100)
		putchar(' ');
	if (path_count->count < 10)
		putchar(' ');
	putnbr(path_count->count);
	puts("    ");
	putendl(path_count->path);
}

int				hash_print(void)
{
	if (!hash_map_get_size(g_hash))
		putendl("hash: hash table empty");
	else
	{
		putendl("hits    command");
		hash_map_iter(g_hash, (void(*)(void *))&hash_print_bin_pair);
	}
	return (0);
}
