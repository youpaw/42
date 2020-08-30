/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 16:40:10 by mgena             #+#    #+#             */
/*   Updated: 2020/08/22 22:29:19 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <stdio.h>

/*
 * We initialize t_list for filenames, scan dir in which we can find file and returns filenames
*/

t_list *get_files(char *path, char *name)
{
	DIR *d;
	struct dirent *dir;
	t_list *lst = NULL;
	size_t cur_len;

	cur_len = strlen(name);
	printf("%s %s\n", path, name);
	if (!(d = opendir(path)))
		;	//TODO some error when dir doesn't exist
	while ((dir = readdir(d)))
	{
		if (strncmp(dir->d_name, name, cur_len) == 0)
			lst_add_sort(&lst, lst_new(dir->d_name, 1024), (int (*)(const void *, const void *)) &strcmp);
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

t_list		*get_list_files(t_input *input, t_token *token)
{
	char *fullname;
	char *delimiter;
	t_list *lst;
	int i = 0;

		fullname = token->raw;
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
	static t_list	*to_print;
	t_tokens 		*tokens;
	t_token 		*token;

	if (!to_print)
	{

		tokens = lex_str_sub(input_to_str(*input), l_tok, input->cursor_position);
		token = get_last_token(tokens);
		if (token == 0) //cur token shouldn't be anithing (wrong or quote)
			ft_put('\7');
//		else if (token == 1) //cur token end and no command could be added
//			symbol_key_pressed(input, );
		else if (token->type == l_word)
		{
			to_print = get_list_files(input, token);
			if (!to_print->next)
				complete_print(input, &to_print);
		}
		else if (token->type == l_command_name) //cur token is command
			get_command(input);
		return 1;
	}
	else
	{

	}
	destruct_token(&token);
	destruct_tokens(&tokens);
	return 1;
}
