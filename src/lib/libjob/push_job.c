/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_job.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:13:11 by mgena             #+#    #+#             */
/*   Updated: 2020/11/15 19:19:19 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"

int		push_job(t_job *job)
{
	t_job	*tmp;

	if (!job)
		return (-1);
	if (!g_first_job)
		g_first_job = job;
	else
	{
		tmp = g_first_job;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = job;
	}
	return (0);
}
