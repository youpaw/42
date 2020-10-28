//
// Created by Darth Butterwell on 10/24/20.
//

#include "readline.h"
#include "cc_str.h"
#include "cc_mem.h"

static t_predict_token *init_token(t_lexer *lexer, t_slice *slice)
{
	t_predict_token *token;
	t_token			last_token;

	token = xmalloc(sizeof(t_predict_token));
	if (slice->state == l_dollar)
	{
		token->type = r_param;
		lexer->begin++;
		if (lexer->raw[lexer->begin] == '{')
			lexer->begin++;
	}
	else if (lexer->tokens->size)
	{
		vec_get_last(&last_token, lexer->tokens);
		if (is_delimiter(last_token.type))
			token->type = r_cmd;
		else if (is_operator(last_token.type) || \
		last_token.type == l_io_number || last_token.type == l_assignment_word)
			token->type = r_file;
	}
	else
		token->type = r_cmd;
	token->raw = strsub(lexer->raw, lexer->begin, lexer->size - lexer->begin);
	token->original_len = lexer->size - lexer->begin;
	return (token);
}

static void 	skip_special_chars(t_lexer *lexer)
{
	static char special[] = "'\"(";
	int cnt;

	while (lexer->begin < lexer->size)
	{
		cnt = 0;
		while (special[cnt] && lexer->raw[lexer->begin] != special[cnt])
			cnt++;
		if (!special[cnt])
			break ;
		lexer->begin++;
	}
}

t_predict_token *get_predict_token(char *raw, size_t len)
{
	t_lexer			lexer;
	t_slice			last_slice;
	t_predict_token *token;
	char			*sub;

	if (!raw || !*raw)
		return (NULL);
	sub = strsub(raw, 0, len);
	lex_raw(&lexer, sub, l_tok);
	vec_get_last(&last_slice, lexer.slices);
	if (last_slice.state == l_dollar && \
	!strncmp(lexer.raw + last_slice.index, "$(", 2))
		token = get_predict_token(lexer.raw + last_slice.index + 2, \
        strlen(lexer.raw + last_slice.index + 2));
	else
	{
		skip_special_chars(&lexer);
		token = init_token(&lexer, &last_slice);
	}
	lex_del(&lexer);
	free(sub);
	return (token);
}