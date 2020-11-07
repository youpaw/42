//
// Created by Azzak Omega on 11/4/20.
//

#include "jobs.h"
#include "cc_str.h"
#include "cc_hash_map.h"
#include "env.h"
#include "alias.h"

static int	has_stopped_jobs(void)
{
	t_job *j;

	j = g_first_job;
	while (j)
	{
		if (job_is_stopped(j))
			return (1);
		j = j->next;
	}
	return (0);
}

static void	free_all_data(void)
{
	free_all_jobs();
	vec_del(&g_job_queue);
	hash_map_del(&g_env);
	hash_map_del(&g_inter_env);
	av_del();
	hash_map_del(&g_aliases);
}

void	exit_shell(int exit_code)
{
	if (g_can_exit || !has_stopped_jobs())
	{
		// save history and free variables
		free_all_data();
		exit(exit_code);
	}
	fdputendl("There are stopped jobs.", 2);
	g_can_exit = 1;
}
