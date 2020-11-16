/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_job.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:13:11 by mgena             #+#    #+#             */
/*   Updated: 2020/11/15 19:19:19 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"
#include "cc_str.h"

void	free_job(t_job **job)
{
	t_job	*j;

	if (!job || !(j = *job))
		return ;
	strdel(&(j->command));
	queue_remove(j->index);
	free_processes(j->first_process);
	free(j->first_process);
	free(j);
	j = NULL;
}
