/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_etx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:52:34 by dbutterw          #+#    #+#             */
/*   Updated: 2020/11/12 19:11:12 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <unistd.h>
#include "env.h"

int			handle_etx(t_inp *inp)
{
	put_cursor_to_the_end(inp);
	write(STDOUT_FILENO, "\n", 1);
	if (inp->hist_storage)
		free(inp->hist_storage);
	del_input(inp);
	g_exit_code = 1;
	return (1);
}
