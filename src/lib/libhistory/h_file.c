/*_init(const char *) - принимает строку с абсолютным путем до файла, запускается один раз.Если файла истории нет она должна его создать с такими правами доступа как у ~/ .history

Int write_to_history(const char *command) - принимает команду и дописывает ее в конец файла инициализации.
void get_reset() - сбрасывает счётчик и при последующем вызове команд get * они будут работать с самого начала.*/
#include "cc.h"
#include "h_dlist.h"
#include "history.h"
# include <fcntl.h>
# include <sys/stat.h>

static int	g_fd = -1;
static const char g_separator[] = "\n----------------------\n";

int		create_or_open(const char *path)
{
	return (open(path, O_CREAT | O_APPEND | O_RDWR | O_FSYNC, S_IRUSR | S_IWUSR ));
}

int		h_init(const char *path)
{
	if (path == NULL)
	{
		return (2);
	}
	if (g_fd != -1)
	{
		return (3);
	}
	g_fd = create_or_open(path);
	if (g_fd < 0)
	{
		//debug_printf
		//perror("create file failed\n");
		return (E_FAIL);
	}

	return (lst_load(g_fd, g_separator, h_append));
}

void		h_close()
{
	if (g_fd != -1)
	{
		close(g_fd);
		g_fd = -1;
	}
	h_free();
}

int h_save_new()
{
	if (g_fd == -1)
	{
		return (E_FAIL);
	}
	return (lst_save(&h_get_head()->list, g_fd, g_separator));
}