//
// Created by Darth Butterwell on 10/16/20.
//

#include "lexer.h"
#include "cc_str.h"

static int	match_end(t_lexer *lexer, size_t start_token_index, t_token *token)
{
	char	*end;
	size_t	index;
	int		error;

	end = strjoin(token->raw, "\n");
	index = lexer->size - 1;
	if (lexer->raw[index] != 4)
		while (index && lexer->raw[index - 1] != '\n')
			index--;
	error = E_INCINP;
	if (lexer->raw[index] == 4 || (index && !strcmp(lexer->raw + index, end)))
	{
		if (lexer->raw[index] == 4)
			putendl("");
		token->raw = strsub(lexer->raw, lexer->begin,index - lexer->begin);
		token->type = l_word;
		vec_rm_at(lexer->tokens, start_token_index);
		vec_push_at(lexer->tokens, token, start_token_index);
		lexer->raw[lexer->begin] = '\0';
		lexer->size = strlen(lexer->raw);
		lexer->index = lexer->size;
		error = 0;
	}
	free(end);
	return (error);
}

static int	get_end(t_vec *tokens, size_t start_token_index, t_token *end)
{
	const char	*arr[1];

	vec_get_at(end, tokens, start_token_index);
	if (end->type != l_word)
	{
		if (end->type == l_newline)
			arr[0] = token_type_to_string(l_newline);
		else
			arr[0] = end->raw;
		error_print(E_UNEXPTOK, (const char **) arr);
		return (E_UNEXPTOK);
	}
	return (0);
}

static int	tokenize_end(t_lexer *lexer)
{
	int error;
	t_state current;
	t_slice slice;

	error = 0;
	slice.index = lexer->index;
	slice.state = l_unset;
	vec_push(lexer->slices, &slice);
	while (lexer->index < lexer->size)
	{
		current = get_current_state(lexer);
		if ((error = lex_map(lexer, current)) != E_OK)
			break ;
		if (lexer->raw[lexer->index] == '\n')
			break ;
		lexer->index++;
	}
	lexer->index++;
	if (!error && lexer->index >= lexer->size)
		error = E_INCINP;
	if (!error)
		vec_rm_last(lexer->slices);
	return (error);
}

int 		vld_heredoc(t_lexer *lexer)
{
	t_token	end;
	size_t	start_token_index;

	int error;

	start_token_index = lexer->tokens->size;
	error = tokenize_end(lexer);
	if (!error && !(error = get_end(lexer->tokens, start_token_index, &end)))
		error = match_end(lexer, start_token_index, &end);
	if (!error)
		vec_rm_last(lexer->slices);
	return (error);
}