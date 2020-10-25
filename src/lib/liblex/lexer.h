//
// Created by Andrew Brazhenko on 2020-02-24.
//


// прежде чем приступать к работе нужно вдоль и поперек изучить ссылки

//RELATED LINKS:
//https://unix.stackexchange.com/questions/448521/what-separators-does-the-lexer-of-bash-use-to-break-a-command-into-words
//https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html#tag_02_03 {2.3 Token recognition, 2.10.1}


// 1. A <newline> shall be returned as the token identifier NEWLINE.

// 2. If the token is an operator, the token identifier for that operator
//shall result.

// 3.If the string consists solely of digits and the delimiter character
// is one of '<' or '>', the token identifier IO_NUMBER shall be returned.

// 4.Otherwise, the token identifier TOKEN results.


#ifndef LEXER_H
# define LEXER_H
# define N_BRACES 4
# define N_STATES 6
# define SLICES_STACK_SIZE 5
# define BRACES_STACK_SIZE 5
# define TOKENS_STACK_SIZE 15
# define N_LEX_FLAGS 1
# define N_LEX_STAGES 3
# define N_TOKEN_TYPES 17
# define N_TOKEN_OPERATORS 12
# define N_TOKEN_DELIMITERS 5
# define N_TOKEN_REDIRECTIONS 4
# include <stddef.h>
# include "cc_vec.h"
# include "error.h"

enum e_token_type
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
	l_word,
	l_token
};

struct s_operator
{
	char	*operator;
	int		size;
};

struct		s_token
{
	char					*raw;
	enum e_token_type		type;
};

struct		s_tokens
{
	char 					*raw;
	enum e_error_code		error; // код ошибки, будет добавлено позже.
	struct s_token			**tokens; // массив токенов
	size_t					size; // размер массива
	size_t					index;
};

enum e_state{
	l_back_slash,
	l_single_quote,
	l_double_quote,
	l_dollar,
	l_history,
	l_heredoc,
	l_unset
};

enum e_brace{
	l_double_round_brace,
	l_round_brace,
	l_figure_brace,
	l_square_brace
};

enum e_stage{
	l_tok,
	l_vld,
	l_exp
};

enum e_flag{
	l_print_command
};

struct s_slice{
	enum e_state	state;
	size_t			index;
};

struct s_lexer{
	char					*raw;
	size_t					index;
	size_t					size;
	t_vec					*slices;
	t_vec					*tokens;
	size_t					begin;
	char 					flags[N_LEX_FLAGS];
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

struct s_brace_raw{
	char	*open;
	char	*close;
	int		len;
};

int			is_redirection(t_token_type type);
int 		is_delimiter(t_token_type type);
int 		is_operator(t_token_type type);
int			is_number(const char *str);

int			get_brace(const char *str, t_brace *brace);
t_token_type get_operator(const char *str, t_operator *op);

t_token_type recognize_token(t_lexer *lexer);
t_token_type recognize_operator(t_lexer *lexer, t_token_type type);

int			match_brace(t_lexer *lexer, t_brace brace);
int 		match_bang(t_lexer *lexer);
int 		match_tilda(t_lexer *lexer);

void		strjoin_expanded(t_lexer *lexer, size_t index, const char *expand, int pad);

int 		tok_single_quote(t_lexer *lexer);
int 		tok_double_quote(t_lexer *lexer);
int 		tok_dollar(t_lexer *lexer);
int 		tok_bang(t_lexer *lexer);
int 		tok_unset(t_lexer *lexer);

int 		vld_bang(t_lexer *lexer);
int 		vld_heredoc(t_lexer *lexer);
int 		vld_back_slash(t_lexer *lexer);

int 		exp_back_slash(t_lexer *lexer);
int 		exp_single_quote(t_lexer *lexer);
int 		exp_double_quote(t_lexer *lexer);
int 		exp_dollar(t_lexer *lexer);
int 		exp_unset(t_lexer *lexer);

t_state		get_current_state(t_lexer *lexer);
int			lex_map(t_lexer *lexer, t_state current);
void 		lex_del(t_lexer *lexer);
int			lex_err(t_lexer *lexer, int error);
int			lex_raw(t_lexer *lexer, const char *raw, t_stage stage);

void 		destruct_token(t_token **token);
int			expand_token(t_token *token);

t_tokens	*get_tokens(t_lexer *lexer, int error);
void 		destruct_tokens(t_tokens **tokens);

t_tokens	*validate_str(const char *string);

// prints the array of tokens in the following format
// 1. [ ls ] [ word ]

void 		print_tokens(t_tokens *tokens);
const char	*token_type_to_string(t_token_type t);

#endif
