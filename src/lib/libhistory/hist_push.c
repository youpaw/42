/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:54:42 by fmallist          #+#    #+#             */
/*   Updated: 2020/11/10 15:59:49 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"
#include "cc.h"

int		hist_push(const char *cmd)
{
	char *new;

	if (cmd)
	{
		new = strdup(cmd);
		vec_push(g_hist.commands, &new);
		hist_reset_cur_ind();
		return (0);
	}
	return (-1);
}
