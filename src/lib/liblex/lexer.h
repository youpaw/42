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

# define MAX_LEXEM_LEN 1024
# define N_TOKEN_TYPES 19
# include <stddef.h>

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

struct		s_tokens
{
	char		*raw; // здесь должен лежать в первозданном виде поток символов, который пришел на вход
	int			error; // код ошибки, будет добавлено позже.
	struct s_token *tokens; // массив токенов
	size_t		size; // размер массива
};

typedef struct s_tokens t_tokens;
typedef struct s_token t_token;
typedef enum e_token_type t_token_type;
/*
**  lex_* returns t_token ptr allocated my malloc().
*/

t_tokens	*lex_stream(int fd);
t_tokens	*lex_str(const char *string);;
void 		destruct_tokens(t_tokens **tokens);

// prints the array of tokens in the following format
// 1. [ ls ] [ word ]

void 		print_tokens(t_tokens *tokens);

static const char *g_token_types_map[N_TOKEN_TYPES] = {
		"undefined",
		"word",
		"name",
		"and_if",
		"or_if",
		"double_semi",
		"newline",
		"io_number",
		"double_less",
		"double_great",
		"less_and",
		"great_and",
		"less_great",
		"double_less_dash",
		"clobber",
		"left_brace",
		"right_brace",
		"bang",
		"token"
};

const char		*type_to_string(t_token_type t);

# define	E_LEXER 10
# define	E_UNDEFINED_TOKEN E_LEXER + 1

#endif
