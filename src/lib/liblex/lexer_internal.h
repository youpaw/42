#ifndef LEXER_INTERNAL_H
#define LEXER_INTERNAL_H

#include "lexer.h"
#include <stdlib.h>
#include "lists.h"
#include "cc.h"
#include "stream.h"


struct		s_token_list
{
	char *raw; // здесь должен лежать в первозданном виде поток символов, который пришел на вход
	int			error; // код ошибки, будет добавлено позже.
	t_list *tokens; // массив токенов
};

typedef struct s_token_list t_tlist;


void		free_token(t_token *t);
void		destruct_tlist(t_tlist *tokens);
t_tlist		*tokenize(const char *string);
void		tokenize_string(t_tlist *tokens, const char *string);
t_tokens	*to_tokens(t_tlist*);
void		add_token(char *raw, t_token_type type);

t_tokens	*create_empty_tokens();


int		try_parse_type(const char *t, t_token_type *type);
int		try_one(const char *t, t_token_type *type);
int		try_other(const char *t, t_token_type *type);
int		try_operator(t_stream*);
int		handle_operator_start(t_stream *s);
int		try_quote(t_stream *s);
int		process_quote(t_stream *s, char quote);


char *tokens_to_string(t_tokens *tokens);
int	is_operator(t_token_type t);

#endif