/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_reset_cur_ind.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:26:40 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:26:43 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

void		hist_reset_cur_ind(void)
{
	g_hist.cur_ind = g_hist.commands->size;
}
