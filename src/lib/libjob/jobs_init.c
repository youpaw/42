//
// Created by Azzak Omega on 10/8/20.
//

#include <sys/types.h>
#include <termios.h>
#include <unistd.h>
#include <signal.h>
#include "cc_str.h"
#include <stdlib.h>
#include "jobs.h"

pid_t			g_pgid;
struct termios	g_tmodes;
int				g_terminal;
int				g_is_interactive;
t_job				*g_first_job = NULL;
t_vec				*g_job_queue = NULL;

/* Make sure the shell is running interactively as the foreground job
   before proceeding. */

void	jobs_init(void)
{
	/* See if we are running interactively.  */
	g_terminal = STDIN_FILENO;
	g_is_interactive = isatty(g_terminal);
	if (g_is_interactive)
	{
		g_job_queue = vec_new(10, sizeof(int), NULL);
		/* Loop until we are in the foreground.  */
		while (tcgetpgrp(g_terminal) != (g_pgid = getpgrp()))
			kill (-g_pgid, SIGTTIN);

		/* Ignore interactive and job-control signals.  */
		signal (SIGINT, SIG_IGN);
		signal (SIGQUIT, SIG_IGN);
		signal (SIGTSTP, SIG_IGN);
		signal (SIGTTIN, SIG_IGN);
		signal (SIGTTOU, SIG_IGN);
		//signal (SIGCHLD, SIG_IGN);

		/* Put ourselves in our own process group.  */
		g_pgid = getpid();
		if (setpgid(g_pgid, g_pgid) < 0)
		{
			fdputendl("Couldn't put the shell in its own process group", STDERR_FILENO);
			exit(1);
		}

		/* Grab control of the terminal.  */
		tcsetpgrp (g_terminal, g_pgid);

		/* Save default terminal attributes for shell.  */
		tcgetattr (g_terminal, &g_tmodes);
	}
}