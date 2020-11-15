/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_down_arrow.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by hlorrine          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "history.h"
#include "cc_str.h"

int		handle_down_arrow(t_inp *inp)
{
	char *new_hist;

	new_hist = (hist_get_next());
	if (!new_hist)
	{
		if (inp->hist_storage)
		{
			new_hist = inp->hist_storage;
			inp->hist_storage = NULL;
		}
		else
		{
			puts("\7");
			return (0);
		}
	}
	else
		new_hist = strdup(new_hist);
	clear_display_input(inp);
	reload_input(inp, new_hist);
	return (0);
}
