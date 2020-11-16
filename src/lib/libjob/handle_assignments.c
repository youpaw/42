/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_assignments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by hlorrine          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jobs.h"
#include "env.h"
#include "cc_str.h"

void	handle_assignments(t_process *process)
{
	t_ast		*ast;

	ast = process->ast->left;
	while (ast)
	{
		if (ast->token && ast->token->type == l_assignment_word)
			env_update(ast->token->raw);
		ast = ast->right;
	}
}
