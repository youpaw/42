//
// Created by Azzak Omega on 10/30/20.
//
#include "jobs.h"
#include "cc_str.h"
#include "cc_char.h"
#include "cc_num.h"


#include <stdio.h>

/*
** ----------------
*/
static void print_process(t_process *p)
{
	printf("      %d status=%d completed=%d stopped=%d\n", p->pid,
		   p->status, p->completed, p->stopped);
}

void	print_job_info(t_job *job)
{
	t_process	*p;

	printf("%d notified=%d %s\n", job->pgid, job->notified, job->command);
	p = job->first_process;
	while (p)
	{
		print_process(p);
		p = p->next;
	}
}

/*
** ----------------
*/

static void print_job_status(t_job *job)
{
	if (job_is_completed(job))
		puts("Done\t");
	else if (job_is_stopped(job))
		puts("Stopped\t");
	else
		puts("Running\t");

}

static char	get_spec(t_job *job, int is_job_builtin)
{
	const int	cur_index = queue_get_current(is_job_builtin);
	const int 	last_index = queue_get_last(is_job_builtin);

	if (job->index == cur_index)
		return ('+');
	if (job->index == last_index)
		return ('-');
	return (' ');
}


void	print_job_formatted(t_job *job, int is_job_builtin)
{
	if (!job)
	{
		putendl("job is NULL");
		return ;
	}
	putchar('[');
	putnbr(job->index);
	putchar(']');
	putchar(get_spec(job, is_job_builtin));
	putchar(' ');
	print_job_status(job);
	puts("PID: ");
	putnbr(job->pgid);
	puts("\t");
	puts(job->command);
	puts("\n");
	//print_job_info(job);
}
/*
int			print_job_status(t_job *j, int verbose, t_job_print_mode mode)
{
	char	*msg;

	if (!j)
		return (0);
	if (job_is_completed(j))
	{
		if (!j->fg)
		{
			msg = get_exit_str(last_process_status(j->first_process));
			format_job_info(j, msg, "", mode);
			ft_strdel(&msg);
		}
		return (1);
	}
	else if ((job_is_stopped(j) && !j->notified))
		notify_stopped_job(j, mode);
	else if (verbose && !j->fg)
		format_job_info(j, "Running", "&", mode);
	return (0);
}
void				print_job_info_by_mode(t_job *j, const char *state, const char *bg,
									t_job_opt opt)
{
	t_st_cmd	*st_cmd;
	t_process	*p;

	st_cmd = get_st_cmd(NULL);
	zsh_newline(st_cmd);
	if (opt == DEFAULT)
		ft_dprintf(STDOUT_FILENO, "[%d] %c %-28s %s%s\n", j->num, j->current,
				   state, j->command, bg);
	else if (opt == PID)
	{
		p = j->first_process;
		while (p)
		{
			ft_dprintf(STDOUT_FILENO, "%d\n", p->pid);
			p = p->next;
		}
	}
	else if (opt == LONG)
		display_long(j, bg);
}

*/

int	get_job_index_from_queue(const char *str)
{
	if (!str)
		return (queue_get_current(1));
	if (str[0] == '+')
		return (queue_get_current(1));
	if (str[0] == '-')
		return (queue_get_last(1));
	if (is_number(str))
		return (atoi(str));
	return (-1);
}

