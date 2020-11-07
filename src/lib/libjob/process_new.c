//
// Created by youpaw on 10/11/20.
//

#include "jobs.h"
#include "cc_mem.h"
#include <unistd.h>

t_process	*process_new(void)
{
	t_process *process;

	process = xmalloc(sizeof(t_process));
	process->next = NULL;
	process->ast = NULL;
	process->argv = NULL;
	process->env = NULL;
	process->completed = 0;
	process->stopped = 0;
	process->status = 0;
	process->stdin = STDIN_FILENO;
	process->stdout = STDOUT_FILENO;
	process->stderr = STDERR_FILENO;
	return (process);
}