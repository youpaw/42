/*_init(const char *) - ��������� ������ � ���������� ����� �� �����, ����������� ���� ���.���� ����� ������� ��� ��� ������ ��� ������� � ������ ������� ������� ��� � ~/ .history

Int write_to_history(const char *command) - ��������� ������� � ���������� �� � ����� ����� �������������.
void get_reset() - ���������� ������� � ��� ����������� ������ ������ get * ��� ����� �������� � ������ ������.*/
#include "cc.h"
# include <fcntl.h>
# include <sys/stat.h>

int	g_fd = -1;

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
		perror("create file failed\n");
	}
	return (g_fd >= 0 ? E_OK : E_FAIL);
}

void		h_close()
{
	if (g_fd != -1)
	{
		close(g_fd);
		g_fd = -1;
	}
}

int h_save_new()
{
	if (g_fd == -1)
	{
		return (E_FAIL);
	}
}
/*
int h_get_prev(char *out)
{
	if (out == NULL)
	{
		return (E_FAIL);
	}
	//if (!has_previous())
	{
		*out = 0;
		return (E_FAIL);
	}

}

int h_get_next(char *out)
{
	if (out == NULL)
	{
		return (E_FAIL);
	}
	//if (!has_previous())
	{
		*out = 0;
		return (E_FAIL);
	}

}*/