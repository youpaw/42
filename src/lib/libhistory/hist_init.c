#include <unistd.h>
#include <fcntl.h>
#include "history.h"
#include "cc.h"

t_hist		g_hist;

void hist_init(const char *home_dir)
{
	int file_fd;
	char *line;

	g_hist.commands = vec_new(HIST_FILE_SIZE, sizeof(char *),
							  (void (*)(void *)) strdel);
	if (!home_dir || access(home_dir, F_OK) == -1)
		g_hist.file_path = NULL;
	else
		g_hist.file_path = strjoin(home_dir, "/.42sh_history");
	if ((file_fd = open(g_hist.file_path, O_RDONLY, S_IREAD | S_IWRITE)) == -1)
		return;
	while (get_next_line(file_fd, &line) > 0)
	{
		if (strlen(line))
			vec_push(g_hist.commands, &line);
		else
			free(line);
	}
	free(line);
	g_hist.cur_ind = g_hist.commands->size;
	close(file_fd);
}
