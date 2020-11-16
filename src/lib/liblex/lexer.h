/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <azomega@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 13:44:15 by azomega           #+#    #+#             */
/*   Updated: 2020/11/15 18:25:57 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# define N_BRACES 3
# define N_STATES 6
# define SLICES_STACK_SIZE 5
# define BRACES_STACK_SIZE 5
# define TOKENS_STACK_SIZE 15
# define N_LEX_FLAGS 2
# define N_LEX_STAGES 3
# define N_TOKEN_TYPES 19
# define N_TOKEN_OPERATORS 12
# define N_TOKEN_DELIMITERS 5
# define N_TOKEN_REDIRECTIONS 6
# define N_INC_INP_TYPES 3
# include <stddef.h>
# include "cc_vec.h"
# include "error.h"

enum						e_token_type
{
	l_and_if,
	l_or_if,
	l_double_less,
	l_double_great,
	l_less_and,
	l_great_and,
	l_and,
	l_or,
	l_less,
	l_great,
	l_semi,
	l_newline,
	l_bang,
	l_io_number,
	l_assignment_word,
	l_command_name,
	l_filename,
	l_here_end,
	l_word,
	l_token
};

struct						s_operator
{
	char					*operator;
	int						size;
};

struct						s_token
{
	char					*raw;
	enum e_token_type		type;
};

struct						s_tokens
{
	char					*raw;
	enum e_error_code		error;
	struct s_token			**tokens;
	size_t					size;
	size_t					index;
};

enum						e_state
{
	l_back_slash,
	l_single_quote,
	l_double_quote,
	l_dollar,
	l_history,
	l_heredoc,
	l_unset
};

enum						e_brace
{
	l_round_brace,
	l_figure_brace,
	l_square_brace
};

enum						e_stage
{
	l_tok,
	l_vld,
	l_exp
};

enum						e_flag
{
	l_print_command,
	l_cmd_appeared
};

struct						s_slice
{
	enum e_state			state;
	size_t					index;
};

struct						s_lexer
{
	char					*raw;
	size_t					index;
	size_t					size;
	t_vec					*slices;
	t_vec					*tokens;
	size_t					begin;
	char					flags[N_LEX_FLAGS];
	enum e_stage			stage;
};

typedef enum e_state		t_state;
typedef struct s_slice		t_slice;
typedef enum e_brace		t_brace;
typedef enum e_stage		t_stage;
typedef struct s_lexer		t_lexer;
typedef enum e_token_type	t_token_type;
typedef struct s_operator	t_operator;
typedef struct s_token		t_token;
typedef struct s_tokens		t_tokens;

struct						s_brace_raw
{
	char					*open;
	char					*close;
	int						len;
};

int							is_redirection(t_token_type type);
int							is_delimiter(t_token_type type);
int							is_doublequote_esc(char c);

int							get_brace(const char *str, t_brace *brace);
t_token_type				get_operator(const char *str, t_operator *op);

t_token_type				recognize_token(t_lexer *lexer);

int							match_parameter(t_lexer *lexer);
int							match_brace(t_lexer *lexer, t_brace brace);
int							match_bang(t_lexer *lexer);
int							match_tilda(t_lexer *lexer);
int							match_heredoc(t_lexer *lexer);

void						strjoin_expanded(t_lexer *lexer, size_t index,
						const char *expand, int pad);

int							tok_single_quote(t_lexer *lexer);
int							tok_double_quote(t_lexer *lexer);
int							tok_dollar(t_lexer *lexer);
int							tok_bang(t_lexer *lexer);
int							tok_unset(t_lexer *lexer);

int							vld_bang(t_lexer *lexer);
int							vld_heredoc(t_lexer *lexer);
int							vld_back_slash(t_lexer *lexer);

int							exp_back_slash(t_lexer *lexer);
int							exp_single_quote(t_lexer *lexer);
int							exp_double_quote(t_lexer *lexer);
int							exp_dollar(t_lexer *lexer);
int							exp_unset(t_lexer *lexer);

t_state						get_current_state(t_lexer *lexer);
int							lex_map(t_lexer *lexer, t_state current);
void						lex_del(t_lexer *lexer);
int							lex_err(t_lexer *lexer, int error);
int							lex_raw(t_lexer *lexer, const char *raw,
				t_stage stage);

void						destruct_token(t_token **token);
int							expand_token(t_token *token);

t_tokens					*get_tokens(t_lexer *lexer, int error);
void						destruct_tokens(t_tokens **tokens);

int							replace_alias(t_lexer *lexer, t_token *token);
t_tokens					*validate_str(const char *string);

const char					*token_type_to_string(t_token_type t);

#endif
