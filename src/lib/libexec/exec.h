//
// Created by youpaw on 26.04.2020.
//

#ifndef EXEC_H
#define EXEC_H

# include "parser.h"
# include "env.h"
# include <stddef.h>
# define EXEC_VEC_CAPACITY 15

int 	is_path(const char *str);

char 	**get_args(t_ast *ast);
t_ast	**get_redirect_nodes(t_ast *ast);

int 	expand_ast(t_ast *ast);

void	prepare_exec_env(t_ast *ast);
int 	prepare_redirect(t_ast *ast, int **fd_arr);

int		stdio_backup(int fd[3]);
void 	stdio_reset(int fd[3]);
void 	close_fds(int *fd_arr, int n_fd);

void	exec_simple_cmd(t_ast *ast);
void	exec_pipe_seq(t_ast *ast);
void	exec_pipeline(t_ast *ast);
void	exec_and_or(t_ast *ast);
void	exec_list(t_ast *ast);
void	exec_complete_cmd(t_ast *ast);
void	exec(t_ast *ast);

#endif //EXEC_H
