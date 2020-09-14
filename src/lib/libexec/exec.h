//
// Created by youpaw on 26.04.2020.
//

#ifndef EXEC_H
#define EXEC_H

# include "parser.h"
# include <stddef.h>

int					exec_io_file(t_ast *ast);
int					exec_filename(t_ast *ast);
int					exec_io_redirect(t_ast *ast);
int					exec_cmd_suffix(t_ast *ast);
int					exec_cmd_prefix(t_ast *ast);
int					exec_simple_cmd(t_ast *ast);
int					exec_command(t_ast *ast);
int					exec_pipe_seq(t_ast *ast);
int					exec_pipeline(t_ast *ast);
int					exec_and_or(t_ast *ast);
int					exec_list(t_ast *ast);
int					exec_complete_cmd(t_ast *ast);
int					exec(t_ast *ast);

#endif //EXEC_H
