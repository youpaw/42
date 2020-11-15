/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str_to_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:54:42 by fmallist          #+#    #+#             */
/*   Updated: 2020/11/10 15:59:49 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "cc_mem.h"
#include "cc_char.h"
#include "cc_str.h"
#include "termcap.h"

void	put_str_to_input(t_inp *inp, char *part)
{
	size_t	i;
	t_let	let;
	int		len;

	i = 0;
	if (!part)
		return ;
	while (part[i])
	{
		bzero(let.ch, 5);
		len = utf8_sizeof_symbol(part[i]);
		strncpy(let.ch, &part[i], len);
		if (len >= 2)
			i += check_for_utf8_comb_character(&part[i], let.ch, len);
		handle_symbol_key(inp, let.ch);
		i += len;
	}
	free(part);
}
