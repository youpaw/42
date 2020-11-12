//
// Created by Maxon Gena on 9/1/20.
//

#include "readline.h"
#include <dirent.h>
#include "cc_str.h"
#include "cc.h"
#include "ft_select.h"

#include <stdio.h>
#include <stdbool.h>

static void check_cr(char filename[1027])
{
	char *cr;

	if ((cr = strrchr(filename, 13)))
	{
		strcpy(cr, "^M");
	}

}

static t_list *get_file_from_name(struct dirent *dir)
{
	char filename[1027];
	t_list *file;
	*filename = '\0';
	if (DT_DIR == dir->d_type)
	{
		strcpy(filename, dir->d_name);
		check_cr(filename);
		strcat(filename, "/");
		file = lst_new(filename, 1025);
	}
	else
	{
		file = lst_new(dir->d_name, 1024);
	}
	return (file);

}

/*
 * We initialize t_list for filenames, scan dir in which we can find file and returns filenames
*/

t_list *get_list_files(char *path, char *name, int check_exe)
{
	DIR *d;
	struct dirent *dir;
	t_list *lst = NULL;
	char *fullname;

	if (!(d = opendir(path)))
		return NULL;
	fullname = xmalloc(sizeof(char) * (strlen(path) + 1025));
	*fullname = 0;
	while ((dir = readdir(d)))
	{
		if (strncmp(dir->d_name, name, strlen(name)) == 0)
		{
			if (!*name && (!strcmp(".", dir->d_name) || !strcmp("..", dir->d_name)))
				continue;
			strcpy(fullname, path);
			strcat(fullname, "/");
			strcat(fullname, dir->d_name);
			if (!check_exe || !access(path, X_OK))
				lst_add_sort(&lst, get_file_from_name(dir), (int (*)(const void *, const void *)) &strcmp);
			*fullname = 0;
		}
	}
	free(fullname);
	closedir(d);
	lst_circle(lst);
	return (lst);
}

/*
 * Splits fullname into path and name,  and put them into filename[0] and [1] respectively
 */

char	**get_filename(char *fullname)
{
	char *delimiter;
	char **filename;

	filename = xmalloc(sizeof(char*) * 2);
	fullname = strdup(fullname);
	delimiter = strrchr(fullname, '/');

	if (delimiter)
	{
		if (!(delimiter[1]))
		{
			filename[0] = strdup(fullname);
			filename[1] = strdup("");
		}
		else if (delimiter == fullname)
		{
			filename[0] = strdup("/");
			filename[1] = strdup(fullname + 1);
		}
		else
		{
			*delimiter = '\0';
			filename[0] = strdup(fullname);
			filename[1] = strdup(delimiter + 1);
		}
	}
	else
	{
		filename[0] = strdup("./");
		filename[1] = strdup(fullname);
	}
	free(fullname);
	return (filename);
}

void handle_file_token(t_inp *input, t_prdct_tkn *token, int acc_m)
{
	t_list *files;
	char 	*part;
	char **filename;

	filename = get_filename(token->raw);
	files = get_list_files(filename[0], filename[1], acc_m);
	if (!files)
		handle_key(" \0\0\0", input);
	else
	{
		part = find_same_part(files, filename[1]);
		if (part)
		{
			put_str_to_input(input, part);
			lst_del_circle(&files, NULL);
		}
		else
		{
			select_choise(convert_list_2_selection(files), input, filename[1]);
			lst_del_circle(&files, NULL);
		}
	}
	free(filename[0]);
	free(filename[1]);
	free(filename);

}