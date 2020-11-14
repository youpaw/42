/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbutterw <dbutterw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:52:34 by dbutterw          #+#    #+#             */
/*   Updated: 2020/11/12 19:11:12 by dbutterw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"
#include <unistd.h>
#include "cc_str.h"

int		redirect_heredoc(t_ast *leafs, t_process *process)
{
	int pfd[2];

	if (pipe(pfd) < 0)
		return (1);
	if (!is_standard_io(process->stdin))
		close(process->stdin);
	fdputs(leafs->left->left->token->raw, pfd[1]);
	process->stdin = pfd[0];
	close(pfd[1]);
	return (0);
}
