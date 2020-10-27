/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 16:36:36 by mgena             #+#    #+#             */
/*   Updated: 2020/08/14 18:29:15 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "cc.h"

t_selection	*get_arguments(int argc, char **argv)
{
	t_selection	*res;
	int			i;
	char		*word;

	i = 1;
	res = NULL;
	while (i < argc)
	{
		word = strdup(argv[i++]);
		res = add_doubly_list(res, word, strlen(word));
	}
	return (res);
}

void		ft_select(int argc, char **argv)
{
	t_selection *arguments;
	char		*selections;

//	main_init();
	arguments = get_arguments(argc, argv);
	selection_storage(arguments);
	selections = select_args(arguments);
//	return_tty();
	free(selections);
}
