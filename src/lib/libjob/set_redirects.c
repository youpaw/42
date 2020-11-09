//
// Created by Darth Butterwell on 11/7/20.
//

#include "jobs.h"
#include <unistd.h>

int	set_redirects(t_process *p)
{
	if (prepare_redirect(p->ast, p))
		return (1);
	if (p->stdin != STDIN_FILENO)
	{
		dup2(p->stdin, STDIN_FILENO);
		close(p->stdin);
	}
	if (p->stdout != STDOUT_FILENO)
	{
		dup2(p->stdout, STDOUT_FILENO);
		close(p->stdout);
	}
	if (p->stderr != STDERR_FILENO)
	{
		dup2(p->stderr, STDERR_FILENO);
		close(p->stderr);
	}
	return (0);
}
