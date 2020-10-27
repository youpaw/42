//
// Created by Maxon Gena on 9/1/20.
//

#include "readline.h"
#include <dirent.h>
#include "cc_str.h"
#include "cc.h"

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

static t_list *get_list_files(char *path, char *name)
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
			lst_add_sort(&lst, get_file_from_name(dir), (int (*)(const void *, const void *)) &strcmp);
		}
	}
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
		if (!(*(delimiter + 1)))
		{
			strcpy(filename[0], fullname);
			strcpy(filename[1], "");
		}
		if (delimiter == fullname)
		{
			strcpy(filename[0], "/");
			strcpy(filename[1], fullname + 1);
		}
		*delimiter = '\0';
		strcpy(filename[0], fullname);
		strcpy(filename[1], delimiter + 1);
	}
	else
	{
		strcpy(filename[0], "./");
		strcpy(filename[1], fullname);
	}
	strdel(&fullname);
	return (filename);
}

void print_part(t_input *input, char *part)
{
	size_t i;
	t_letter let;

	i = 0;
	bzero(let.ch, 5);
	while (part[i])
	{
		let.ch[0] = part[i++];
		handle_key(let.ch, input);
	}
	free(part);
}

int	get_input_ending(char *name, char *part)
{
	size_t i;
	char *part_cpy;

	i = 0;
	while (name[i])
		i++;
	if (!part[i])
	{
//		strdel(&part);
		return (0);
	}
	part_cpy = strdup(&part[i]);
	strdel(&part);
	part = part_cpy;
	return (1);
}

void 	handle_file_token(t_input *input, t_predict_token *token)
{
	t_list *files;
	char 	*part;
	char **filename;

	filename = get_filename(token->raw);
	files = get_list_files(filename[0], filename[1]);
	if (!files)
		return ;
	part = find_same_part(files, filename[1]);
	if (part)
	{
		print_part(input, part);
		strdel(&filename[0]);
		strdel(&filename[1]);
		free(filename);
	}
	else
	{
//		choise_making(files, input);
;
	}
//	else
//		;
//	tty_restore();
//	exit(0);
}