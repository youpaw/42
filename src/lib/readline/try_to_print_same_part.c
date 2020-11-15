/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_to_print_same_part.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:54:42 by fmallist          #+#    #+#             */
/*   Updated: 2020/11/10 15:59:49 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "cc_str.h"

void	inner_circle(t_list *files, t_list *cur, char *same, size_t len)
{
	int i;

	while (cur != files && *same)
	{
		i = 0;
		while (same[i] == ((char*)cur->content)[i + len])
			i++;
		same[i] = 0;
		cur = cur->next;
	}
}

char	*find_same_part(t_list *files, char *filename)
{
	unsigned int	i;
	unsigned int	len;
	t_list			*cur;
	char			same[1024];

	if (!files)
		return (NULL);
	len = strlen(filename);
	if (files->next == files)
		return (strdup(&(files->content)[len]));
	i = 0;
	cur = files->next;
	while (((char*)cur->content)[i + len] == ((char*)files->content)[i + len])
	{
		same[i] = ((char*)files->content)[i + len];
		i++;
	}
	same[i] = 0;
	cur = cur->next;
	inner_circle(files, cur, same, len);
	if (!*same)
		return (NULL);
	else
		return (strdup(same));
}
