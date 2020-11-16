/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlorrine <hlorrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by hlorrine          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by hlorrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "lexer.h"
# include "error.h"
# define N_NODE_TYPES 13
# define N_MAX_TOKEN_TYPES 6

enum						e_node_type
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

struct						s_ast
{
	enum e_node_type	type;
	struct s_token		*token;
	struct s_ast		*left;
	struct s_ast		*right;
};

typedef struct s_ast		t_ast;
typedef enum e_node_type	t_node_type;

t_ast						*node_here_end(t_tokens *tokens);
t_ast						*node_filename(t_tokens *tokens);
t_ast						*node_io_here(t_tokens *tokens);
t_ast						*node_io_file(t_tokens *tokens);
t_ast						*node_io_redirect(t_tokens *tokens);
t_ast						*node_cmd_suffix(t_tokens *tokens);
t_ast						*node_cmd_prefix(t_tokens *tokens);
t_ast						*node_simple_cmd(t_tokens *tokens);
t_ast						*node_pipe_seq(t_tokens *tokens);
t_ast						*node_pipeline(t_tokens *tokens);
t_ast						*node_and_or(t_tokens *tokens);
t_ast						*node_list(t_tokens *tokens);
t_ast						*node_complete_cmd(t_tokens *tokens);

void						del_ast(t_ast **node);
t_ast						*new_ast_node(t_node_type type);
int							get_node_token(t_ast *node, t_tokens *tokens);
t_ast						*sh_parse(t_tokens *tokens);

#endif
