//
// Created by youpaw on 10/6/20.
//

#include <unistd.h>

void 	close_fds(int *fd_arr, int n_fd)
{
	int index;

	index = 0;
	while (index < n_fd)
		close(fd_arr[index++]);
}