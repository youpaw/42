/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_default_pipe_fds.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:54:42 by fmallist          #+#    #+#             */
/*   Updated: 2020/11/10 15:59:49 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	set_default_pipe_fds(int *in_out_fds, int *pipe_fds)
{
	in_out_fds[0] = STDIN_FILENO;
	in_out_fds[1] = STDOUT_FILENO;
	pipe_fds[0] = STDIN_FILENO;
	pipe_fds[1] = STDOUT_FILENO;
}
