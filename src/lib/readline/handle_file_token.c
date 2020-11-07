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
	size_t len;

	filename = xmalloc(sizeof(char*) * 2);
	len = strlen(fullname);
	filename[0] = xmalloc(sizeof(char) * (len + 1));
	filename[1] = xmalloc(sizeof(char) * (len + 1));
	fullname = strdup(fullname);
	delimiter = strrchr(fullname, '/');

	if (delimiter)
	{
		if (!(delimiter[1]))
		{
			strcpy(filename[0], fullname);
			strcpy(filename[1], "");
		}
		else if (delimiter == fullname)
		{
			strcpy(filename[0], "/");
			strcpy(filename[1], fullname + 1);
		}
		else
		{
			*delimiter = '\0';
			strcpy(filename[0], fullname);
			strcpy(filename[1], delimiter + 1);
		}
	}
	else
	{
		strcpy(filename[0], "./");
		strcpy(filename[1], fullname);
	}
	free(fullname);
	return (filename);
}

void put_str_to_inp(t_input *input, char *part)
{
	size_t i;
	t_letter let;
	int 	len;

	i = 0;
	if (!part)
		return ;
	while (part[i])
	{
		bzero(let.ch, 5);
		len = utf8_sizeof_symbol(part[i]);
		strncpy(let.ch, &part[i], len);
		if (len >= 2)
			i += check_for_utf8_comb_charecter(&part[i], let.ch, len);
		handle_symbol_key(input, let.ch);
		i += len;
	}
	free(part);
}

void handle_file_token(t_input *input, t_predict_token *token, int access_mode)
{
	t_list *files;
	char 	*part;
	char **filename;

	filename = get_filename(token->raw);
//	puts(token->raw);
//	puts("\n");
//	puts(filename[0]);
//	puts("\n");
//	puts(filename[1]);
//	puts("\n");
	files = get_list_files(filename[0], filename[1], access_mode);
	if (!files)
		handle_key(" \0\0\0", input);
	else
	{
		part = find_same_part(files, filename[1]);
		if (part)
		{
			put_str_to_inp(input, part);
			lst_del_circle(&files, NULL);
		}
		else
		{
			clear_last_disp_token(filename[1], input);
			select_choise(convert_list_2_selection(files), input);
			lst_del_circle(&files, NULL);
		}
	}
	free(filename[0]);
	free(filename[1]);
	free(filename);

}