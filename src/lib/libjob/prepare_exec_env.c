/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_exec_env.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:13:11 by mgena             #+#    #+#             */
/*   Updated: 2020/11/15 19:19:19 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	prepare_exec_env(t_ast *ast)
{
	exec_env_init();
	if (!ast)
		return ;
	while (ast)
	{
		if (ast->token && ast->token->type == l_assignment_word)
			exec_env_insert(ast->token->raw);
		ast = ast->right;
	}
}
