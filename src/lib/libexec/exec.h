//
// Created by youpaw on 26.04.2020.
//

#ifndef EXEC_H
#define EXEC_H

# include "parser.h"
# include "env.h"
# include "jobs.h"
# include <stddef.h>

# define EXEC_VEC_CAPACITY 15

char	*get_command(t_tokens *tokens, int async);
char 	**get_args(t_ast *ast);
t_ast	**get_redirect_nodes(t_ast *ast);

int 	expand_ast(t_ast *ast);

void	prepare_exec_env(t_ast *ast);
int 	prepare_redirect(t_ast *ast, t_process *process);

void	exec_simple_cmd(t_ast *ast, t_process *process);
void	exec_pipe_seq(t_ast *ast, t_process *process);
void	exec_pipeline(t_ast *ast, t_job *job);
void exec_and_or(t_ast *ast, t_job *job);
void	exec_list(t_ast *ast, t_tokens *tokens);
void	exec_complete_cmd(t_ast *ast, t_tokens *tokens);
void	exec(t_ast *ast, t_tokens *tokens);

#endif //EXEC_H
