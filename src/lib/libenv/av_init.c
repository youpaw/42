/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   av_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:03:46 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:03:48 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "cc_str.h"

char				*g_av[N_MAX_AV];

static void			av_set(const char **av)
{
	int cnt;

	cnt = 1;
	if (av)
		while (cnt < N_MAX_AV && *av)
			g_av[cnt++] = strdup(*av++);
	while (cnt < N_MAX_AV)
		g_av[cnt++] = NULL;
}

void				av_init(const char *name, const char **av)
{
	g_av[0] = strdup(name);
	av_set(av);
}
