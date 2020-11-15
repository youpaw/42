/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <azomega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:15 by azomega           #+#    #+#             */
/*   Updated: 2020/11/14 15:11:11 by azomega          ###   ########.fr       */
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
