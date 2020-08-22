/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 16:40:10 by mgena             #+#    #+#             */
/*   Updated: 2020/08/22 22:28:54 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "../libcc/cc.h"
#include <stdio.h>

/*
 * We initialize t_list for filenames, scan dir in which we can find file and returns filenames
*/
t_list *get_files(char *path, char *name)
{
	DIR *d;
	struct dirent *dir;
	t_list *lst = NULL;
	t_list *cpy;
	size_t cur_len;

	cur_len = strlen(name);
	printf("%s %s\n", path, name);
	if (!(d = opendir(path)))
		;	//TODO some error when dir doesn't exist
	while ((dir = readdir(d)))
	{

		if (strncmp(dir->d_name, name, cur_len) == 0)
			lst_add_sort(&lst, lst_new(dir->d_name, 1024), 0, (int (*)(const void *, const void *, void *)) &strcmp);
	}
//	cpy = lst;
//	while (cpy)
//	{
//		printf("%s | ", (char*)cpy->content);
//		cpy = cpy->next;
//	}
//	printf("\n");
	return (lst);
}

/*
 * This function returns list of filenames, which equal to first letters fo input
 */

t_list		*get_list_files(t_input *input)
{
	char *fullname;
	char *delimiter;
	t_list *lst;
	char test[8][5] = TEST;
	int i = 0;

//	while (i != 8)
//	{
		fullname = strdup(test[6]); //here will be function, which give me last token
//		printf("Full string: %s\n", test[i++]);
		delimiter = strrchr(fullname, '/');
		if (delimiter)
		{
			*delimiter = '\0';
			lst = get_files(fullname, delimiter + 1);
		}
		else
			lst = get_files("./", fullname);
//	}
	return (lst);
}

void get_command(t_input *input)
{
	;
}

int			autocomplete(t_input *input)
{
	int				token = 2;
	static t_list	*to_print;

	if (!to_print)
	{
//			tokenize();
//			token = get_last_token();
		if (token == 0) //cur token shouldn't be anithing (wrong or quote)
			ft_put('\7');
		else if (token == 1) //cur token end and no command could be added
			symbol_key_pressed(input, ' ');
		else if (token == 2) //cur token is dir
		{
			to_print = get_list_files(input);
			if (!to_print->next)
				complete_print(input, &to_print);
		}
		else if (token == 3) //cur token is command
			get_command(input);
		return 1;
	}
	else
	{

	}
	return 1;
}
