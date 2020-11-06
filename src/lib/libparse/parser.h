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
#include "lexer.h"
#include "error.h"
#define N_NODE_TYPES 13
#define N_MAX_TOKEN_TYPES 7

enum e_node_type
{
	p_cmpl_cmd,
	p_list,
	p_and_or,
	p_pipeline,
	p_pipe_seq,
	p_simple_cmd,
	p_cmd_pref,
	p_cmd_suff,
	p_io_redirect,
	p_io_file,
	p_io_here,
	p_filename,
	p_here_end
};

struct		s_ast
{
	enum e_node_type	type;
	struct s_token		*token;
	struct s_ast		*left;
	struct s_ast		*right;
};

typedef struct s_ast t_ast;
typedef enum e_node_type t_node_type;

t_ast				*node_here_end(t_tokens *tokens);
t_ast 				*node_filename(t_tokens *tokens);
t_ast				*node_io_here(t_tokens *tokens);
t_ast 				*node_io_file(t_tokens *tokens);
t_ast 				*node_io_redirect(t_tokens *tokens);
t_ast 				*node_cmd_suffix(t_tokens *tokens);
t_ast 				*node_cmd_prefix(t_tokens *tokens);
t_ast 				*node_simple_cmd(t_tokens *tokens);
t_ast 				*node_pipe_seq(t_tokens *tokens);
t_ast				*node_pipeline(t_tokens *tokens);
t_ast 				*node_and_or(t_tokens *tokens);
t_ast 				*node_list(t_tokens *tokens);
t_ast 				*node_complete_cmd(t_tokens *tokens);

void 				del_ast(t_ast **node);
t_ast				*new_ast_node(t_node_type type);
int 				get_node_token(t_ast *node, t_tokens *tokens);
t_ast				*parse(t_tokens *tokens);

const char			*node_type_to_string(t_node_type type);

#endif //PARSER_H
