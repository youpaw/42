/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:52:34 by dbutterw          #+#    #+#             */
/*   Updated: 2020/11/12 19:11:12 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "cc_str.h"

static int	(*get_handler(char *key))(t_inp*)
{
	static const t_key_readline_handler hanlders[N_ESC_KEY_HANDLERS] = {
			{"\6", &handle_right_arrow},
			{"\2", &handle_left_arrow},
			{"\177", &handle_backspace},
			{"\t", &handle_tab},
			{"\20", &handle_down_arrow},
			{"\16", &handle_up_arrow},
			{"\3", &handle_etx}
	};
	int									index;

	index = 0;
	while (index < N_ORD_KEY_HANDLERS)
	{
		if (!strcmp(hanlders[index].primary_key, key))
			if (hanlders[index].handler)
				return (hanlders[index].handler);
		index++;
	}
	return (NULL);
}

int			handle_key(char *key, t_inp *input)
{
	int (*handler)(t_inp *);

	if ((handler = get_handler(key)))
		return (handler(input));
	if (!strcmp("\33\133", key))
		return (handle_escape_sequence(input));
	return (handle_symbol_key(input, key));
}
