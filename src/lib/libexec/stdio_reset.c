//
// Created by youpaw on 10/6/20.
//
#include <unistd.h>

void 	stdio_reset(int fd[3])
{
	dup2(fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	dup2(fd[2], STDERR_FILENO);
}