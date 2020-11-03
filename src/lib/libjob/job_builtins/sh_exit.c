//
// Created by Azzak Omega on 9/16/20.
//

#include <stdlib.h>
#include "cc_char.h"
#include "cc_num.h"
#include "error.h"
#include "jobs.h"
#include "cc_str.h"

static int	is_numeric(const char *nb)
{
	if (*nb == '+' || *nb == '-')
		nb++;
	while (*nb)
		if (!isdigit(*nb++))
			return (0);
	return (1);
}

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

void	exit_shell(int exit_code)
{
	if (g_can_exit)
		putendl("Can exit!!!");
	if (g_can_exit || !has_stopped_jobs())
	{
		// save history and free variables
		free_all_jobs();
		exit(exit_code);
	}
	fdputendl("There are stopped jobs", 2);
	g_can_exit = 1;
}

int exit_builtin(const char **av)
{
	if (!av[1])
		exit_shell(0);
	else if (!is_numeric(av[1]))
	{
		error_print(E_NUMARGREQ, av);
		exit_shell(255);
	}
	else if (!av[2])
		exit_shell(atoi(av[1]));
	else
		error_print(E_TOOMANYARGS, av);
	return (0);
}
