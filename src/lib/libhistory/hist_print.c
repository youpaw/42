/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:07:05 by hlorrine          #+#    #+#             */
/*   Updated: 2020/11/12 22:08:05 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"
#include "cc.h"

void	hist_print(void)
{
	int		i;
	char	*str;

	i = 0;
	while (i++ < (int)g_hist.commands->size)
	{
		if (i < 10)
			putchar(' ');
		if (i < 100)
			putchar(' ');
		if (i < 1000)
			putchar(' ');
		putchar(' ');
		putnbr(i);
		puts("  ");
		vec_get_at(&str, g_hist.commands, i - 1);
		putendl(str);
	}
}
