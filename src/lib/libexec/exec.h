/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:13:11 by mgena             #+#    #+#             */
/*   Updated: 2020/11/15 19:19:19 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "parser.h"
# include "env.h"
# include "jobs.h"
# include <stddef.h>

char	*get_command(t_ast *ast);
void	exec_simple_cmd(t_ast *ast, t_process *process);
void	exec_pipe_seq(t_ast *ast, t_process *process);
void	exec_pipeline(t_ast *ast, t_job *job);
void	exec_and_or(t_ast *ast, char is_foreground,
				char is_forked, t_token *token);
void	exec_list(t_ast *ast);
void	exec_complete_cmd(t_ast *ast);
void	sh_exec(t_ast *ast);

#endif
