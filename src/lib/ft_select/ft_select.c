/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <azomega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:15 by azomega           #+#    #+#             */
/*   Updated: 2020/11/14 15:11:11 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "cc_str.h"
#include "cc_lst.h"
#include "cc_char.h"
#include "cc_mem.h"

t_selection	*convert_list_2_selection(t_list *lst)
{
	t_list		*first;
	t_selection	*res;

	res = NULL;
	first = lst;
	res = add_doubly_list(res, lst->content, strlen(lst->content));
	lst = lst->next;
	while (lst != first)
	{
		res = add_doubly_list(res, lst->content, strlen(lst->content));
		lst = lst->next;
	}
	return (res);
}

t_selection	*convert_array_2_selection(char **argv)
{
	t_selection	*res;
	int			i;
	char		*word;

	i = 0;
	res = NULL;
	while (argv[i])
	{
		word = argv[i++];
		res = add_doubly_list(res, word, strlen(word));
	}
	return (res);
}

char		*prepare_choise(t_selection *selection, char *letter)
{
	size_t	i;
	size_t	k;
	char	*ret;

	i = 0;
	k = 0;
	if (*letter == '\33')
	{
		free(letter);
		return (NULL);
	}
	while (!selection->under_cursor)
		selection = selection->next;
	ret = xmalloc(sizeof(char) * ((selection->cstring_len * 2) + 2));
	while (selection->word[i])
	{
		if (selection->word[i] == ' ')
			ret[k++] = '\\';
		ret[k++] = selection->word[i++];
	}
	if (*letter == ' ')
		ret[k++] = ' ';
	ret[k] = '\0';
	free(letter);
	return (ret);
}

char		*ft_select(t_selection *selections)
{
	char	*last_letter;

	select_init();
	g_selection = selections;
	last_letter = select_args(selections);
	last_letter = prepare_choise(selections, last_letter);
	move_start();
	tputs(tgetstr("ve", NULL), 1, putchar);
	g_out.cur_y_pos = 0;
	delete_lst(&selections);
	return (last_letter);
}
