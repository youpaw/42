//
// Created by Darth Butterwell on 11/7/20.
//

#include <unistd.h>

int	is_standard_io(int fd)
{
	return (fd == STDIN_FILENO || fd == STDERR_FILENO || fd == STDOUT_FILENO);
}
