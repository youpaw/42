/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_up_arrow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:54:42 by fmallist          #+#    #+#             */
/*   Updated: 2020/11/10 15:59:49 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "history.h"
#include "cc_str.h"

int	handle_up_arrow(t_inp *inp)
{
	char *new_hist;

	if (!inp->hist_storage)
		inp->hist_storage = input_to_str(*inp, 1);
	new_hist = hist_get_prev();
	if (new_hist)
	{
		new_hist = strdup(new_hist);
		clear_display_input(inp);
		reload_input(inp, new_hist);
	}
	else
		puts("\7");
	return (0);
}
