/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tty_restore.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:54:42 by fmallist          #+#    #+#             */
/*   Updated: 2020/11/15 18:25:11 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void		tty_restore(void)
{
	tcsetattr(0, TCSAFLUSH, &(g_tty_backup));
}
