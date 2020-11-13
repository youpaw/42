/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:26:35 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:26:38 by hlorrine         ###   ########.fr       */
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
