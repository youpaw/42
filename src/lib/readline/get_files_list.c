//
// Created by Maxon Gena on 9/1/20.
//

#include <stdio.h>
#include "readline.h"

void check_cr(char filename[1027])
{
	char *cr;

	if ((cr = strrchr(filename, 13)))
	{
		strcpy(cr, "^M");
	}

}

t_list *get_file_list(struct dirent *dir)
{
	char filename[1027];
	t_list *file;
	char *cpy;
	if (DT_DIR == dir->d_type)
	{
		strcpy(filename, dir->d_name);
		check_cr(filename);
		cpy = filename;
		strcat(filename, "/");
		file = lst_new(filename, 1025);
	}
	else
	{
		file = lst_new(dir->d_name, 1024);
	}
	return (file);

}

t_list *get_files(char *path, char *name)
{
	DIR *d;
	struct dirent *dir;
	t_list *lst = NULL;
	size_t cur_len;
	int dot_flg;

	cur_len = strlen(name);
	dot_flg = (*name == '.') ? 1 : 0;
	if (!(d = opendir(path)))
		return NULL;
	while ((dir = readdir(d)))
	{
		if (strncmp(dir->d_name, name, cur_len) == 0)
		{
			if (!dot_flg && (!strcmp(".", dir->d_name) || !strcmp("..", dir->d_name)))
				continue;
			lst_add_sort(&lst, get_file_list(dir), (int (*)(const void *, const void *)) &strcmp);
		}
	}
	return (lst);
}

/*
 * This function returns list of filenames, which equal to first letters fo input
 */

t_list		*get_list_files(t_input *input, t_token *token)
{
	char *fullname;
	char *delimiter;

	fullname = token->raw;
	delimiter = strrchr(fullname, '/');
	if (delimiter)
	{
		if (!(delimiter + 1))
			return get_files(fullname, "");
		if (delimiter == fullname)
			return get_files("/", fullname + 1);
		*delimiter = '\0';
		return get_files(fullname, delimiter + 1);
	}
	else
		return get_files("./", fullname);
}

void set_word(t_input *input, t_token *token)
{
	t_list *files;
	int list_len;

	files = get_list_files(input, token);
	list_len = lst_get_size(files);
}