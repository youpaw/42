/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by hlorrine          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"
#include "optparse.h"
#include "error.h"
#include "cc_str.h"

static t_job_print_mode	get_job_print_mode(char *options)
{
	t_job_print_mode	mode;
	char				opt;

	if (!options)
		return (JPM_DEFAULT);
	opt = options[strlen(options) - 1];
	if (opt == 'p')
		mode = JPM_PID;
	else
		mode = JPM_LONG;
	free(options);
	return (mode);
}

static int				print_specific_jobs(const char **av,
								t_job_print_mode mode)
{
	int			err_code;
	t_job		*job;
	int			index;
	const char	*error_args[2];

	err_code = 0;
	error_args[0] = "jobs";
	update_status();
	while (*av)
	{
		index = queue_get_job_index_by_str(*av);
		if (!(job = find_job_by_index(index)))
		{
			error_args[1] = *av;
			error_print(E_NOSUCHJOB, error_args);
			err_code = E_NOSUCHJOB;
		}
		else if (g_has_job_control)
			print_job_formatted(job, 1, mode);
		av++;
	}
	return (err_code);
}

static int				print_all_jobs(t_job_print_mode mode)
{
	t_job	*job;
	t_job	*next_job;

	if ((job = g_first_job) && g_has_job_control)
		while (job->next)
		{
			next_job = job->next;
			print_job_formatted(job, 1, mode);
			if (job_is_completed(job))
				remove_job_by_index(job->index);
			job = next_job;
		}
	return (0);
}

int						jobs(const char **av)
{
	t_parsed_opt	opt_res;
	int				skip;
	int				err_code;

	g_can_exit = 1;
	update_status();
	if (!(skip = optparse(av, "pl", &opt_res)))
	{
		err_code = print_invalid_option("jobs", opt_res.invalid_opt);
		print_usage(2, "jobs", "[-lp]");
	}
	else if (!av[skip])
		err_code = print_all_jobs(get_job_print_mode(opt_res.options));
	else
		err_code = print_specific_jobs(&av[skip],
										get_job_print_mode(opt_res.options));
	return (err_code);
}
