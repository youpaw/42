#include <unistd.h>
#include <fcntl.h>
#include "history.h"
#include "cc.h"

t_hist		g_hist;

void hist_init(const char *home_dir)
{
	int	file_fd;
	char *line;

	//if (!home_dir || access(home_dir, F_OK | R_OK | W_OK | X_OK) == -1)
	//need more checks for file and permissions
	g_hist.commands = vec_new(HIST_FILE_SIZE, sizeof(char *), free);
	if (!home_dir || access(home_dir, F_OK) == -1)
		g_hist.file_path = NULL;
	else
		g_hist.file_path = strjoin(home_dir, "/.bash_history");
	if ((file_fd = open(g_hist.file_path, O_RDONLY)) == -1)
		return ;
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
//	char **str;
//
//	t_avl_pair pair;
//	pair.key = str[9];
//	pair.value = str[9];
//	avl_insert(g_hist->commands_avl, &pair);

	/*
	 * Инициализация структуры
	 * Берешь из глобалки HOME, проверяешь что он существует, strjoin HOME с FILE_NAME в file_path в структуре
	 * commands_avl = avl_new(0, $cmp, NULL)
	 * Если file_path != NULL открыть его и считать в массив commands, считаешь количество и записываешь в size
	 * cur_ind = size
	 */
}