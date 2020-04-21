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
// убрать после мержа ветки лексера в дев

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

t_ast *				node_io_file(t_tokens *tokens);
// все операнды в аттрибут
t_ast * 			node_filename(t_tokens *tokens);
// WORD кладется в атрибут
t_ast * 			node_io_redirect(t_tokens *tokens);
// IO_NUMBER аттрибут, в него кладется указатель на лексему типа l_IO_number
t_ast * 			node_cmd_suffix(t_tokens *tokens);
t_ast * 			node_cmd_prefix(t_tokens *tokens);
t_ast * 			node_simple_cmd(t_tokens *tokens);
// WORD указатель на лексему кладется в attr
t_ast * 			node_command(t_tokens *tokens);
t_ast * 			node_pipe_seq(t_tokens *tokens);
// '|' никуда добавлять не нужно, attr всегда null
t_ast * 			node_pipeline(t_tokens *tokens);
// AND_IF OR_IF это атрибуты, в него кладется указатель на лексемы l_and_if, l_or_if
t_ast * 			node_and_or(t_tokens *tokens);
t_ast * 			node_list(t_tokens *tokens);
// separator_op это атрибут, в него нода separator_op кладет указатель на лексему (асинхронное выполнение команды)
t_ast *				node_complete_cmd(t_tokens *tokens);
//Только нода слева лист, да тупо, но из-за того что урезана грамматика, потом возможно допилим

void 				del_ast_node(t_ast **node);
t_ast				*new_ast_node(t_node_type type);
int 				get_token_attr(t_ast *node, t_tokens *tokens, t_token_type type);
t_ast				*parse(t_tokens *tokens);

#endif //PARSER_H
