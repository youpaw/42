//
// Created by youpaw on 29.02.2020.
//

#ifndef CC_FILE_H
# define CC_FILE_H
# define BUFF_SIZE 256

struct s_file
{
	char *buff;
	int fd;
};

typedef struct s_file t_file;

int	get_next_line(const int fd, char **line);

#endif //FILE_LIB_H
