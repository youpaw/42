//
// Created by Azzak Omega on 10/30/20.
//
#include "jobs.h"
#include "cc_str.h"
#include "cc_char.h"
#include "cc_num.h"


#include <stdio.h>

/*
** ----------------TO REMOVE-------------

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

static char	get_spec(int job_index, int is_job_builtin)
{
	const int	cur_index = queue_get_current(is_job_builtin);
	const int 	last_index = queue_get_last(is_job_builtin);

	if (job_index == cur_index)
		return ('+');
	if (job_index == last_index)
		return ('-');
	return (' ');
}

void    print_job_pid(t_job *job)
{
    putnbr(job->pgid);
    puts("\n");
}

void    print_job_index_with_spec(t_job *job, char spec)
{
    putchar('[');
    putnbr(job->index);
    putchar(']');
    putchar(spec);
    putchar(' ');
}


void	print_job_default(t_job *job, int is_job_builtin)
{
	print_job_index_with_spec(job, get_spec(job->index, is_job_builtin));
	print_job_status(job);
	puts("\t");
	putendl(job->command);
}

void	print_job_long(t_job *job, int is_job_builtin)
{
    print_job_index_with_spec(job, get_spec(job->index, is_job_builtin));
    putnbr(job->pgid);
    putchar(' ');
    print_job_status(job);
    puts(" (signal)");
    puts("\t");
    putendl(job->command);
}

void    print_job_bg(t_job *job)
{
    print_job_index_with_spec(job, ' ');
    print_job_pid(job);
}


void	print_job_formatted(t_job *job, int is_job_builtin, t_job_print_mode mode)
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

