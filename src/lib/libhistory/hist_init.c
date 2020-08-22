//
// Created by Halfhand Lorrine on 8/20/20.
//

#include <unistd.h>
#include <fcntl.h>
#include "history.h"

t_hist		*g_hist;
#include	"cc.h"


int		hist_init(void)
{
	int file_fd;

	g_hist = xmalloc(sizeof(t_hist *));
	if (access(HOME, F_OK) == -1)
		return (1);
	g_hist->file_path = nstrjoin(3, HOME, "/" ,FILE_NAME);
	if ((file_fd = open(g_hist->file_path, O_RDONLY)) == -1)
		return (1);



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