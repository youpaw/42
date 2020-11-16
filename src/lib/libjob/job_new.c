/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <azomega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:15 by azomega           #+#    #+#             */
/*   Updated: 2020/11/14 15:11:11 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"
#include "cc_mem.h"

t_job		*job_new(int is_foreground)
{
	t_job *job;

	job = xmalloc(sizeof(t_job));
	job->next = NULL;
	job->command = NULL;
	job->first_process = NULL;
	job->pgid = 0;
	job->notified = 0;
	job->is_fg = is_foreground;
	job->index = get_new_job_index();
	tcgetattr(g_terminal, &job->tmodes);
	queue_push_back(job->index);
	return (job);
}
