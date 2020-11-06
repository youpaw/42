//
// Created by youpaw on 10/11/20.
//

#include "jobs.h"
#include "cc_str.h"
#include <unistd.h>
#include "builtins.h"

static int	get_job_return_value(t_job *j, int is_foreground, int is_forked)
{
	if (!g_is_interactive)
		return (wait_for_job(j, 0));
	else if (is_foreground)
		return (put_job_in_foreground(j, 0));
	put_job_in_background(j, 0);
	if (is_forked)
		return (wait_for_job_complete(j));
	return (0);
}

int launch_job(t_job *job, int is_foreground, int is_forked)
{
	int			return_value;
	char 		*msg;

	if (!job->first_process->next && is_foreground &&
			((!run_builtin((const char **)job->first_process->argv)) || \
			!run_job_builtin((const char **) job->first_process->argv)))
	{
		job->first_process->completed = 1;
		return (0); //fiiiiiiiiiix
	}
	g_can_exit = 0;
	fork_and_launch_process(job, is_foreground);

	if (!is_forked && !is_foreground)
        print_job_formatted(job, 0, JPM_BG);

	return_value = get_job_return_value(job, is_foreground, is_forked);
	if (WIFSIGNALED(return_value))
	{
		if (WTERMSIG(return_value) == SIGPIPE && job)
			return_value = get_last_process_status(job->first_process);
		else if ((is_forked || is_foreground) &&
					WTERMSIG(return_value) != SIGINT)
		{
			msg = get_status_message(return_value);
			fdputendl(msg, 2);
			strdel(&msg);
		}
	}
	return (return_value);
}