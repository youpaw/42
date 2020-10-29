/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 19:55:56 by mgena             #+#    #+#             */
/*   Updated: 2020/08/14 18:22:11 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "cc_str.h"

//void			escape(void)
//{
////	return_tty();
//	exit(0);
//}

struct winsize	get_winsize(void)
{
	struct winsize ws;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
	ws.ws_row /=2;
	return (ws);
}

char			*join_selection(t_selection *selection, int len, char *res)
{
	int		i;
	char	*tmp;
	int		fin_len;

	i = 0;
	while (i != len)
	{
		if (selection->selected)
		{
			tmp = strjoin(res, selection->word);
			free(res);
			res = tmp;
			tmp = strjoin(res, " ");
			free(res);
			res = tmp;
			i++;
		}
		else
			len--;
		selection = selection->next;
	}
	fin_len = strlen(res);
	if (res[fin_len - 1] == ' ')
		res[fin_len - 1] = '\0';
	return (res);
}

char			*get_args_array(t_selection *selection)
{
	t_selection	*cpy;
	char		*res;
	size_t		len;

	res = strdup("");
	len = 1;
	cpy = selection;
	selection = selection->next;
	while (selection != cpy)
	{
		len++;
		selection = selection->next;
	}
	res = join_selection(selection, len, res);
	return (res);
}
