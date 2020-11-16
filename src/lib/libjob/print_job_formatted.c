/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_job_formatted.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <azomega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:15 by azomega           #+#    #+#             */
/*   Updated: 2020/11/14 15:11:11 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"
#include <stdio.h>
#include "cc_num.h"
#include "cc_str.h"

static void		print_job_index_with_spec(t_job *job, char spec)
{
	putchar('[');
	putnbr(job->index);
	putchar(']');
	putchar(spec);
	putchar(' ');
}

static void		print_job_default(t_job *job, int is_job_builtin)
{
	print_job_index_with_spec(job, get_status_sign_for_job(job->index,
														is_job_builtin));
	print_job_status_str(job);
	puts("\t");
	putendl(job->command);
}

static void		print_job_long(t_job *job, int is_job_builtin)
{
	print_job_index_with_spec(job, get_status_sign_for_job(job->index,
														is_job_builtin));
	putnbr(job->pgid);
	putchar(' ');
	print_job_status_str(job);
	puts("\t");
	putendl(job->command);
}

static void		print_job_bg(t_job *job)
{
	print_job_index_with_spec(job, ' ');
	print_job_pid(job);
}

void			print_job_formatted(t_job *job, int is_job_builtin,
							t_job_print_mode mode)
{
	if (mode == JPM_DEFAULT)
		print_job_default(job, is_job_builtin);
	else if (mode == JPM_BG)
		print_job_bg(job);
	else if (mode == JPM_LONG)
		print_job_long(job, is_job_builtin);
	else
		print_job_pid(job);
}
