//
// Created by Darth Butterwell on 11/7/20.
//

#include "lexer.h"
#include "alias.h"
#include "cc_str.h"

static void backup_lexer(t_lexer *lexer, t_lexer *bck)
{
	bck->raw = lexer->raw;
	bck->index = lexer->index;
	bck->size = lexer->size;
	bck->begin = lexer->begin;
}

static void restore_lexer(t_lexer *lexer, t_lexer *bck)
{
	free(lexer->raw);
	lexer->raw = bck->raw;
	lexer->index = bck->index;
	lexer->size = bck->size;
	lexer->begin = bck->begin;
}

static void set_lexer(t_lexer *lexer, const char *alias)
{
	lexer->raw = strdup(alias);
	lexer->size = strlen(alias);
	lexer->index = 0;
	lexer->begin = 0;
}

int 		replace_alias(t_lexer *lexer, t_token *token)
{
	const char	*alias;
	t_lexer		bck;
	t_state		current;
	int			error;

	if (!(alias = alias_get_value(token->raw)))
		return (0);
	vec_rm_last(lexer->tokens);
	backup_lexer(lexer, &bck);
	set_lexer(lexer, alias);
	while (lexer->index <= lexer->size)
	{
		current = get_current_state(lexer);
		if ((error = lex_map(lexer, current)) != E_OK)
			break ;
		lexer->index++;
	}
	restore_lexer(lexer, &bck);
	return (error);
}