//
// Created by Azzak Omega on 8/23/20.
//

#include <fcntl.h>
#include <unistd.h>
#include "history.h"
#include "cc.h"

void	hist_save(void)
{
	int 	i;
	int		file_fd;
	char	*str;

	//need more checks
	//if ((file_fd = open(g_hist.file_path, O_WRONLY)) == -1)
	if ((file_fd = open(g_hist.file_path, O_WRONLY | O_TRUNC)) == -1)
		return ;
	i = 0;
	putnbr(g_hist.commands->size);
	putendl("");
	if (g_hist.commands->size > HIST_FILE_SIZE)
		i = (int)g_hist.commands->size - HIST_FILE_SIZE;
	while (i < g_hist.commands->size)
	{
		vec_get_at(&str, g_hist.commands, i++);
		fdputendl(str, file_fd);
	}
	putendl("hist saved");
	vec_del(&g_hist.commands);
	close(file_fd);
}
