/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by hlorrine          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "cc_char.h"
#include "cc_str.h"
#include <termcap.h>
#include <unistd.h>

void	redraw_input(t_inp inp, char *str)
{
	size_t	i;
	char	*prompt;
	int		len;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '\n')
		{
			tputs(tgetstr("do", NULL), 1, putchar);
			tputs(tgetstr("cr", NULL), 1, putchar);
			prompt = get_prompt(inp.y_pos);
			puts(prompt);
			free(prompt);
			i++;
		}
		else
		{
			len = utf8_sizeof_symbol(*str);
			write(STDOUT_FILENO, &str[i], len);
			i += len;
		}
	}
}
