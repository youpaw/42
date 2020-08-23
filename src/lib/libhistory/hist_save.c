//
// Created by Azzak Omega on 8/23/20.
//

#include <fcntl.h>
#include <unistd.h>
#include "history.h"
#include "cc.h"

void	hist_save(void)
{
	int i;
	int	file_fd;

	//need more checks
	//if ((file_fd = open(g_hist.file_path, O_WRONLY)) == -1)
	if ((file_fd = open(g_hist.file_path, O_WRONLY | O_TRUNC)) == -1)
		return ;
	i = 0;
	putnbr(g_hist.size);
	putendl("");
	if (g_hist.size > HIST_FILE_SIZE)
		i = g_hist.size - HIST_FILE_SIZE;
	while (i < g_hist.size)
		fdputendl(g_hist.commands[i++], file_fd);
	putendl("hist saved");
	close(file_fd);
}
