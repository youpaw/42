/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtin_by_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:54:42 by fmallist          #+#    #+#             */
/*   Updated: 2020/11/10 15:59:49 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"
#include "env.h"

int		run_builtin_by_index(t_process *p, int index)
{
	int err_code;

	prepare_exec_env(p->ast->left);
	err_code = exec_builtin_by_index((const char **)p->argv, index);
	free(p->argv);
	p->argv = NULL;
	exec_env_del();
	return (err_code);
}
