//
// Created by youpaw on 26.04.2020.
//

#ifndef EXEC_H
#define EXEC_H

# include "parser.h"
# include "env.h"
# include <stddef.h>

int 	is_path(const char *str);

void	exec_io_file(t_ast *ast);
void	exec_filename(t_ast *ast);
void	exec_io_redirect(t_ast *ast);
void	exec_cmd_suffix(t_ast *ast);
void	exec_cmd_prefix(t_ast *ast);
void	exec_simple_cmd(t_ast *ast);
void	exec_command(t_ast *ast);
void	exec_pipe_seq(t_ast *ast);
void	exec_pipeline(t_ast *ast);
void	exec_and_or(t_ast *ast);
void	exec_list(t_ast *ast);
void	exec_complete_cmd(t_ast *ast);
void	exec(t_ast *ast);

#endif //EXEC_H
