/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_job_notification.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:13:11 by mgena             #+#    #+#             */
/*   Updated: 2020/11/15 19:19:19 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"

void	notify_and_remove_completed_job(t_job *j)
{
	if (!j->is_fg)
		print_job_formatted(j, 0, JPM_DEFAULT);
	remove_job_by_index(j->index);
}

void	do_job_notification(void)
{
	t_job	*j;
	t_job	*jnext;

	update_status();
	j = g_first_job;
	while (j)
	{
		jnext = j->next;
		if (job_is_completed(j))
			notify_and_remove_completed_job(j);
		else if (job_is_stopped(j) && !j->notified)
		{
			print_job_formatted(j, 0, JPM_DEFAULT);
			j->notified = 1;
			j->is_fg = 0;
		}
		j = jnext;
	}
}
