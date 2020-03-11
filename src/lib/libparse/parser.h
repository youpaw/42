//
// Created by youpaw on 10.03.2020.
//

/*
На гите в таске лежит урезанная грамматика шелл, она учитывает только команды с консоли, парсинга шелл скриптов пока не будет.
 Парсинг производится от вышестоящей ноды к нижестоящей
 Извне вызывается функция parse, которая инициализирует дерево и дергает самую верхнюю ноду (complete_command)
 Функции нод принимают на вход дерево, в которое будут добавалять свои ноды, массив лексем, и индекс обрабатываемой лексемы
 Функции возвращают количество обработанных лексем
 Если функция ноды возвращает 0, значит она не смогла создать ноду из-за несоответствия лексем в списке грамматике
 В таком случае вышестоящая нода либо пробует следующую конфигурацию грамматики либо возвращает текущее колиество обработанных лексем (если конфигурации закончились)
 Если в парсер возвращается количество обработанных лексем меньше общего количества лексем выкидывается ошибка и возвращается NULL, большее количество обработанныз лексем вернутся не должно

 Структура дерева хранит в себе тип ноды, аттрибут (например async у ноды лист, описнно ниже), и ветви
 По умолчанию ноды слева хранят нижестоящие ноды, а справа равностоящие ноды, пример:
 		list
 		/	\
	and_or	list

 Исключение составляет нода simple_command, у нее слева и справа только нижестоящие ноды:
 		simple_command
 		/			\
	cmd_prefix		cmd_suffix

 Остальные ноды имеют только ветвь слева

 У большинства нод есть атрибуты, описаны детальнее под каждой нодой

 Атрибуты нужны для того чтобы дерево оставалось бинарным, обычно в нее кладется указатель на лексему
*/
#ifndef PARSER_H
# define PARSER_H
//# include "lexer.h" раскоментить после мержа ветки лексера в дев
# include <stddef.h>

// убрать после мержа ветки лексера в дев

# define MAX_LEXEM_LEN 1024
enum e_node_type
{
	p_cmpl_cmd,
	p_list,
	p_pipeline,
	p_pipe_seq,
	p_command,
	p_simple_cmd,
	p_cmd_pref,
	p_cmd_suff,
	p_redirect_list,
	p_io_redirect,
	p_filename,
	p_sep_op
};

enum e_token_type
{
	l_undefined,
	l_word,
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


typedef struct s_tokens t_tokens;
typedef struct s_token t_token;
typedef enum e_token_type t_token_type;
// убрать после мержа ветки лексера в дев

struct		s_tokens
{
	char		*raw; // здесь должен лежать в первозданном виде поток символов, который пришел на вход
	int			error; // код ошибки, будет добавлено позже.
	struct s_token *tokens; // массив токенов
	size_t		size; // размер массива
};

struct		s_ast
{
	enum e_node_type type;
	void			*attrs;
	struct s_ast	*left;
	struct s_ast	*right;
};

typedef struct s_ast t_ast;
typedef enum e_node_type t_node_type;


int 				node_separator_op(t_ast *ast, t_tokens *tokens, int parsed);
// не создает нод, его вызывает complete_command с текущим деревом, он либо кладет в аттрибут ноды указатель на лексему и возвращает 1 либо возвращает 0
int 				node_io_file(t_ast *ast, t_tokens *tokens, int parsed);
// все операнды в аттрибут
int 				node_filename(t_ast *ast, t_tokens *tokens, int parsed);
// WORD кладется в атрибут
int 				node_io_redirect(t_ast *ast, t_tokens *tokens, int parsed);
// IO_NUMBER аттрибут, в него кладется указатель на лексему типа l_IO_number
int 				node_redirect_list(t_ast *ast, t_tokens *tokens, int parsed);
int 				node_cmd_suffix(t_ast *ast, t_tokens *tokens, int parsed);
int 				node_cmd_prefix(t_ast *ast, t_tokens *tokens, int parsed);
int 				node_simple_cmd(t_ast *ast, t_tokens *tokens, int parsed);
// WORD указатель на лексему кладется в attr
int 				node_command(t_ast *ast, t_tokens *tokens, int parsed);
int 				node_pipe_seq(t_ast *ast, t_tokens *tokens, int parsed);
// '|' никуда добавлять не нужно, attr всегда null
int 				node_pipeline(t_ast *ast, t_tokens *tokens, int parsed);
// AND_IF OR_IF это атрибуты, в него кладется указатель на лексемы l_and_if, l_or_if
int 				node_list(t_ast *ast, t_tokens *tokens, int parsed);
// separator_op это атрибут, в него нода separator_op кладет указатель на лексему (асинхронное выполнение команды)
int					node_complete_cmd(t_ast *ast, t_tokens *tokens, int parsed);
//Только нода слева лист, да тупо, но из-за того что урезана грамматика, потом возможно допилим

t_ast				*parse(t_token *tokens);

#endif //PARSER_H
