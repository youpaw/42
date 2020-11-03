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

t_list *get_list_files(char *path, char *name, int access_mode)
{
	DIR *d;
	struct dirent *dir;
	t_list *lst = NULL;

	if (!(d = opendir(path)))
		return NULL;
	while ((dir = readdir(d)))
	{
		if (strncmp(dir->d_name, name, strlen(name)) == 0)
		{
			if (!*name && (!strcmp(".", dir->d_name) || !strcmp("..", dir->d_name)))
				continue;
			if (!access(dir->d_name, access_mode))
				lst_add_sort(&lst, get_file_from_name(dir), (int (*)(const void *, const void *)) &strcmp);
		}
	}
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
	free(fullname);
	return (filename);
}

int	check_for_utf8_comb_charecter(char *prev, char *letter, size_t len)
{
	if (!strncmp(&prev[len], "\xcc\x86", 2))
	{
		if (!strncmp(prev, "\xd0\x98", 2))
			letter[1] = '\x99';
		else if (!strncmp(prev, "\xd0\xb8", 2))
			letter[1] = '\xb9';
		return 2;
	}
	if (!strncmp(&prev[len], "\xcc\x88", 2))
	{
		if (!strncmp(prev, "\xd0\xb5", 2))
			strcpy(letter, "\xd1\x91");
		else if (!strncmp(prev, "\xd0\x95", 2))
			strcpy(letter, "\xd0\x81");
		return (2);
	}
	return (0);
}

void put_str_to_inp(t_input *input, char *part)
{
	size_t i;
	t_letter let;
	int 	len;

	i = 0;
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