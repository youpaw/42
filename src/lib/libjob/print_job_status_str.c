/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_job_status_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <azomega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:15 by azomega           #+#    #+#             */
/*   Updated: 2020/11/14 15:11:11 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"
#include "cc_str.h"

void		print_job_status_str(t_job *job)
{
	char	*msg;

	if (job_is_completed(job) || job_is_stopped(job))
	{
		msg = get_status_message(get_last_process_status(job->first_process));
		puts(msg);
		strdel(&msg);
	}
	else
		puts("Running\t");
}
