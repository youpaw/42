/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin_by_index.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <azomega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:15 by azomega           #+#    #+#             */
/*   Updated: 2020/11/14 15:11:11 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "jobs.h"

int			exec_builtin_by_index(const char **av, int index)
{
	static int (*builtins_funcs[N_BUILTINS])(const char **) = {
			exit_builtin, sh_set, sh_unset, sh_cd, sh_export, sh_hash, sh_echo,
			sh_alias, sh_unalias,
			jobs, fg_builtin, bg_builtin, sh_history, type};

	if (index)
		g_can_exit = 0;
	return (builtins_funcs[index](av));
}
