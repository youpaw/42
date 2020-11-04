//
// Created by Fidelia Mallister on 11/4/20.
//

#include "exec.h"
#include <unistd.h>

void 	init_process_ioerr(t_process *process, int from, int to) // c
{
	if (STDIN_FILENO == from)
	{
		if (!is_standard_io(process->stdin))
			close(process->stdin);
		process->stdin = to;
	}
	else if (STDERR_FILENO == from)
	{
		if (!is_standard_io(process->stderr))
			close(process->stderr);
		process->stderr = to;
	}
	else if (STDOUT_FILENO == from)
	{
		if (!is_standard_io(process->stdout))
			close(process->stdout);
		process->stdout = to;
	}
}