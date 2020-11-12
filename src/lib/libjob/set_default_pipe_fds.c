//
// Created by Azzak Omega on 11/12/20.
//

#include <unistd.h>

void	set_default_pipe_fds(int *in_out_fds, int *pipe_fds)
{
	in_out_fds[0] = STDIN_FILENO;
	in_out_fds[1] = STDOUT_FILENO;
	pipe_fds[0] = STDIN_FILENO;
	pipe_fds[1] = STDOUT_FILENO;
}