//
// Created by Fidelia Mallister on 11/5/20.
//

#include "exec.h"
#include <unistd.h>

int		minus(t_process *process, int from)
{
	//int dev_null;

	//printf("HERE BITCH\n");
	//dev_null = open("/dev/null", O_WRONLY, 0644);
	if (from == STDOUT_FILENO)
	{
		//process->stdout = dev_null;
		//close(process->stdout);
	}
	else if (from == STDERR_FILENO)
	{
		//process->stderr = dev_null;
		//close(process->stderr);
	}
	else if (from == STDIN_FILENO)
	{
		//process->stdin = dev_null;
		//close(process->stdin);
	}
	return (0);
}
