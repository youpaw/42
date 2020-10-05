//
// Created by youpaw on 10/6/20.
//
#include <unistd.h>

int stdio_backup(int *fd)
{
	fd[0] = dup(STDIN_FILENO);
	fd[1] = dup(STDOUT_FILENO);
	fd[2] = dup(STDERR_FILENO);
	if (fd[0] < 0 || fd[1] < 0 || fd[2] < 0)
		return (1);
	return (0);
}