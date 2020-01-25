#include "cc.h"

int	file_exists(const char *path)
{
	return (access(path, F_OK) != -1);
}