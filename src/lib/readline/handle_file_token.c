//
// Created by Maxon Gena on 9/1/20.
//

#include "readline.h"
#include <dirent.h>
#include "cc_str.h"
#include "cc.h"
#include "ft_select.h"

static void		check_cr(char filename[1027])
{
	char *cr;

	if ((cr = strrchr(filename, 13)))
		strcpy(cr, "^M");
}

static t_list	*get_file_lst(struct dirent *dir)
{
	char		filename[1027];
	t_list		*file;

	*filename = '\0';
	if (DT_DIR == dir->d_type)
	{
		strcpy(filename, dir->d_name);
		check_cr(filename);
		strcat(filename, "/");
		file = lst_new(filename, 1025);
	}
	else
		file = lst_new(dir->d_name, 1024);
	return (file);
}

static void		del_at_end(DIR *d, char *fullname, t_list *lst)
{
	free(fullname);
	closedir(d);
	lst_circle(lst);
}

/*
** We initialize t_list for filenames,
** scan dir in which we can find file and returns filenames
*/

static t_list	*get_list_files(char *path, char *n, int check_exe)
{
	DIR				*d;
	struct dirent	*dir;
	t_list			*lst;
	char			*fullname;

	lst = NULL;
	if (!(d = opendir(path)))
		return (NULL);
	fullname = xmalloc(sizeof(char) * (strlen(path) + 1025));
	while ((dir = readdir(d)))
	{
		if (strncmp(dir->d_name, n, strlen(n)) == 0)
		{
			if (!*n && (!strcmp(".", dir->d_name) \
				|| !strcmp("..", dir->d_name)))
				continue;
			strcat(strcat(strcpy(fullname, path), "/"), dir->d_name);
			if (!check_exe || !access(path, X_OK))
				lst_add_sort(&lst, get_file_lst(dir), \
				(int (*)(const void *, const void *)) &strcmp);
			*fullname = 0;
		}
	}
	del_at_end(d, fullname, lst);
	return (lst);
}

void			handle_file_token(t_inp *input, t_prdct_tkn *token, int acc_m)
{
	t_list	*files;
	char	*part;
	char	**filename;

	filename = parse_filename(token->raw);
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
