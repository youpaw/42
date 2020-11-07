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
int 	is_minus(t_ast *leafs);

int		redirect_close_stdio(t_process *process, int from);
void 	redirect_init_process_file(t_process *process, int from, int to);
int		redirect_print_error(int errcode, const char *token);
int 	redirect_parse_right_side(t_ast *leafs, int open_options, int can_be_number, int is_maybe_minus);
int 	redirect_parse_left_side(t_ast *leafs, int default_value);
int 	redirect_great_and(t_ast *leafs, t_process *process);
int 	redirect_less_and(t_ast *leafs, t_process *process);
int 	redirect_great(t_ast *leafs, t_process *process, int is_double_great);
int		redirect_less(t_ast *leafs, t_process *process);
int 	redirect_heredoc(t_ast *leafs, t_process *process);
int 	prepare_redirect(t_ast *ast, t_process *process);

void	exec_simple_cmd(t_ast *ast, t_process *process);
void	exec_pipe_seq(t_ast *ast, t_process *process);
void	exec_pipeline(t_ast *ast, t_job *job);
void	exec_and_or(t_ast *ast, char is_foreground, char is_forked, t_token *token);
void	exec_list(t_ast *ast);
void	exec_complete_cmd(t_ast *ast);
void	exec(t_ast *ast);
#endif //EXEC_H
