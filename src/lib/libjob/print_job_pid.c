/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_job_pid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by hlorrine          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cc_str.h"
#include "cc_num.h"
#include "jobs.h"

void	print_job_pid(t_job *job)
{
	putnbr(job->pgid);
	puts("\n");
}
