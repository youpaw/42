//
// Created by youpaw on 26.04.2020.
//

#ifndef EXEC_H
#define EXEC_H

//# include "parser.h" раскоментить после мержа ветки лексера в дев
# include <stddef.h>

// убрать после мержа ветки парсера в дев

# define MAX_LEXEM_LEN 1024

enum e_token_type
{
	l_undefined,
	l_word,
	l_assignment_word,
	l_name,

	l_and_if,
	l_or_if,
	l_double_semi,

	l_newline,
	l_io_number,
	l_double_less,
	l_double_great,
	l_less_and,
	l_great_and,
	l_less_great,
	l_double_less_dash,
	l_clobber,

	l_left_brace,
	l_right_brace,

	l_bang,
	l_token
};

struct		s_token
{
	char 	raw[MAX_LEXEM_LEN];
	enum e_token_type type;
};

struct		s_tokens
{
	char		*raw; // здесь должен лежать в первозданном виде поток символов, который пришел на вход
	int			error; // код ошибки, будет добавлено позже.
	struct s_token *tokens; // массив токенов
	size_t		size; // размер массива
	size_t		index;
};


typedef struct s_tokens t_tokens;
typedef struct s_token t_token;
typedef enum e_token_type t_token_type;

enum e_node_type
{
	p_cmpl_cmd,
	p_list,
	p_and_or,
	p_pipeline,
	p_pipe_seq,
	p_command,
	p_simple_cmd,
	p_cmd_pref,
	p_cmd_suff,
	p_io_redirect,
	p_filename,
	p_io_file
};

struct		s_ast
{
	enum e_node_type type;
	struct s_token	attr;
	struct s_ast	*left;
	struct s_ast	*right;
};

typedef struct s_ast t_ast;
typedef enum e_node_type t_node_type;

// убрать после мержа ветки парсера в дев

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
int 	exec(t_ast *ast);

#endif //EXEC_H
