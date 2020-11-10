//
// Created by Darth Butterwell on 10/24/20.
//

#include "readline.h"
#include "cc_str.h"
#include "cc_mem.h"

static t_prdct_tkn *init_token(t_lexer *lexer, t_slice *slice)
{
	t_prdct_tkn *token;
	t_token			last_token;

	token = xmalloc(sizeof(t_prdct_tkn));
	if (slice->state == l_dollar)
	{
		token->type = r_param;
		if (slice->index == lexer->begin)
			lexer->begin += lexer->raw[lexer->begin] == '{' ? 2 : 1;
	}
	else if (lexer->tokens->size)
	{
		vec_get_last(&last_token, lexer->tokens);
		if (is_delimiter(last_token.type) || last_token.type == l_assignment_word)
			token->type = r_cmd;
		else
			token->type = r_file;
	}
	else
		token->type = r_cmd;
	token->raw = strsub(lexer->raw, lexer->begin, lexer->size - lexer->begin);
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

t_prdct_tkn *get_predict_token(char *raw)
{
	t_lexer			lexer;
	t_slice			last_slice;
	t_prdct_tkn *token;

	if (!raw)
		return (NULL);
	lex_raw(&lexer, raw, l_tok);
	vec_get_last(&last_slice, lexer.slices);
	if (last_slice.state == l_dollar && \
	!strncmp(lexer.raw + last_slice.index, "$(", 2))
		token = get_predict_token(lexer.raw + last_slice.index + 2);
	else
	{
		skip_special_chars(&lexer);
		token = init_token(&lexer, &last_slice);
	}
	lex_del(&lexer);
	return (token);
}