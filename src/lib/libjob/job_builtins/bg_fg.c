/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg_fg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:13:11 by mgena             #+#    #+#             */
/*   Updated: 2020/11/15 19:19:19 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"
#include "error.h"

static int	put_job_in_bg_fg(const char *str, int is_foreground)
{
	t_job	*job;
	int		index;

	index = queue_get_job_index_by_str(str);
	if (!(job = find_job_by_index(index)))
		return (1);
	queue_move_back(index);
	continue_job(job, is_foreground);
	return (0);
}

int			bg_fg(const char **av, int is_foreground)
{
	const char	*error_args[2];

	g_can_exit = 0;
	error_args[0] = av[0];
	if (g_has_job_control && !put_job_in_bg_fg(av[1], is_foreground))
		return (0);
	if (!g_has_job_control)
		error_print(E_NOJOBCONTROL, error_args);
	else
	{
		error_args[1] = av[1] ? av[1] : "current";
		error_print(E_NOSUCHJOB, error_args);
	}
	return (1);
}
