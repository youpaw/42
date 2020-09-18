//
// Created by Maxon Gena on 9/1/20.
//

#include "readline.h"
#include <dirent.h>
#include "cc_str.h"

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

static t_list *scan_dir(char *path, char *name)
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
 * This function returns list of filenames, which equal to first letters fo input
 */

t_list *get_list_files(char *fullname)
{
	char *delimiter;

	delimiter = strrchr(fullname, '/');
	if (delimiter)
	{
		if (!(delimiter + 1))
			return scan_dir(fullname, "");
		if (delimiter == fullname)
			return scan_dir("/", fullname + 1);
		*delimiter = '\0';
		return scan_dir(fullname, delimiter + 1);
	}
	else
		return scan_dir("./", fullname);
}

void 	handle_file_token(t_input *input, t_token *token)
{
	t_list *files;
	char 	*part;

	files  = get_list_files(token->raw);
	part = find_same_part(files, token->raw);
	printf("\n\n\n%s|\n", part);
	tty_restore();
	exit(0);

}