//
// Created by Fidelia Mallister on 11/5/20.
//

#include "exec.h"
#include <unistd.h>

int		redirect_close_stdio(t_process *process, int from)
{
	if (from == STDOUT_FILENO)
		close(process->stdout);
	else if (from == STDERR_FILENO)
		close(process->stderr);
	else if (from == STDIN_FILENO)
		close(process->stdin);
	return (0);
}
