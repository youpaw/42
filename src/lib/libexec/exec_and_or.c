/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_and_or.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by hlorrine          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "jobs.h"
#include "unistd.h"
#include "lexer.h"

void		exec_and_or(t_ast *ast, char is_foreground,
				char is_forked, t_token *token)
{
	t_job	*job;

	if (!token || (!g_exit_code && token->type == l_and_if) \
				|| (g_exit_code && token->type == l_or_if))
	{
		job = job_new(is_foreground);
		exec_pipeline(ast->left, job);
		job->command = get_command(ast->left);
		if (is_forked)
			job->pgid = getpid();
		push_job(job);
		g_exit_code = launch_job(job, is_foreground, is_forked);
		if (job_is_completed(job))
			remove_job_by_index(job->index);
	}
	if (ast->right)
		exec_and_or(ast->right, is_foreground, is_forked, ast->token);
}
