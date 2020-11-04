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

char *get_command(t_ast *ast);
char 	**get_args(t_ast *ast);
t_ast	**get_redirect_nodes(t_ast *ast);

int 	expand_ast(t_ast *ast);

void	prepare_exec_env(t_ast *ast);

int 	is_standard_io(int fd);
int 	is_valid_number(const char *str);
int 	is_minus(t_ast *leafs);
int 	right_side(t_ast *leafs, int open_options, int can_be_number, int is_maybe_minus);
int 	left_side(t_ast *leafs, int default_value);
int 	l_great_and_redirect(t_ast *leafs, t_process *process);
int 	l_less_and_redirect(t_ast *leafs, t_process *process);
void 	init_process_ioerr(t_process *process, int from, int to);
int 	l_great_redirect(t_ast *leafs, t_process *process, int is_double_great);
int		l_less_redirect(t_ast *leafs, t_process *process);
int 	l_heredoc_redirect(t_ast *leafs, t_process *process);
int 	prepare_redirect(t_ast *ast, t_process *process);

void	exec_simple_cmd(t_ast *ast, t_process *process);
void	exec_pipe_seq(t_ast *ast, t_process *process);
void	exec_pipeline(t_ast *ast, t_job *job);
void	exec_and_or(t_ast *ast, char is_foreground, char is_forked, t_token *token);
void	exec_list(t_ast *ast);
void	exec_complete_cmd(t_ast *ast);
void	exec(t_ast *ast);
#endif //EXEC_H
