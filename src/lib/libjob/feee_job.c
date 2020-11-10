/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feee_job.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youpaw <youpaw@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 14:52:31 by youpaw            #+#    #+#             */
/*   Updated: 2020/11/10 19:10:02 by youpaw           ###   ########.fr       */
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
