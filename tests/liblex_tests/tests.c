#include "cc.h"
#include <stdio.h>
#include "asserts.h"
#include "lexer.h"
#include "lexer_internal.h"


void	test_error(const char *str, int e)
{
	t_tokens *tokens = lex_str(str);

	assert_int_equals(0, tokens->size);
	assert_int_equals(e, tokens->error);
	assert_str_equals(str, tokens->raw);
	assert_str_equals("", tokens_to_string(tokens));
	assert_is_null(tokens->tokens);

	destruct_tokens(tokens);
}

void	test(const char *str, const char *expected, int size)
{
	t_tokens *tokens = lex_str(str);

	assert_int_equals(E_OK, tokens->error);
	assert_int_equals(size, tokens->size);
	assert_str_equals(str, tokens->raw);
	assert_str_equals(expected, tokens_to_string(tokens));

	destruct_tokens(tokens);
}

void		test_lex()
{
	test("ls -la", "[ ls ] [ word ]\n[ -la ] [ word ]\n", 2);
	test("\"`1`\"", "[ `1` ] [ word ]\n", 1);
	test("1#2\n3", "[ 1 ] [ io_number ]\n[ 3 ] [ io_number ]\n", 2);

	test("1", "[ 1 ] [ io_number ]\n", 1);
	test("ls>1.txt", "[ ls ] [ word ]\n[ > ] [ word ]\n[ 1.txt ] [ word ]\n", 3);

	test(" 1", "[ 1 ] [ io_number ]\n", 1);
	test("1 ", "[ 1 ] [ io_number ]\n", 1);
	test("    1", "[ 1 ] [ io_number ]\n", 1);
	test("1    ", "[ 1 ] [ io_number ]\n", 1);
	test("    1      ", "[ 1 ] [ io_number ]\n", 1);
	test(" 1  2  ", "[ 1 ] [ io_number ]\n[ 2 ] [ io_number ]\n", 2);

	test("!", "[ ! ] [ bang ]\n", 1);
	test(" {", "[ { ] [ left_brace ]\n", 1);
	test("{ ", "[ { ] [ left_brace ]\n", 1);
	test(" { ", "[ { ] [ left_brace ]\n", 1);
	//test("}{", "[ } ] [ right_brace ]\n[ { ] [ left_brace ]\n", 2);
	test("}{", "[ }{ ] [ word ]\n", 1);
	test("{", "[ { ] [ left_brace ]\n", 1);
	test("}", "[ } ] [ right_brace ]\n", 1);
	test("\n", "[ \\n ] [ newline ]\n", 1);
//	test(" ", "[  ] [ word ]\n", 1);
//	test("''", "[  ] [ word ]\n", 1);
//	test("""", "[  ] [ word ]\n", 1);
//	test("\"``\"", "[  ] [ word ]\n", 1);				//"``"
	test("1\n", "[ 1 ] [ io_number ]\n[ \\n ] [ newline ]\n", 2);
	test("1\n2", "[ 1 ] [ io_number ]\n[ \\n ] [ newline ]\n[ 2 ] [ io_number ]\n", 3);

	test("q\\>>", "[ q> ] [ word ]\n[ > ] [ word ]\n", 2);				//q\>>	q>>
	test("q>>", "[ q ] [ word ]\n[ >> ] [ double_great ]\n", 2);
	test("q'>'>", "[ q> ] [ word ]\n[ > ] [ word ]\n", 2);
	test("q'>>'", "[ q>> ] [ word ]\n", 1);
	test(">>>>", "[ >> ] [ double_great ]\n[ >> ] [ double_great ]\n", 2);

	test("\"\\\\\"", "[ \\ ] [ word ]\n", 1);				//"\\" -> \   "
	test("\"\\$\"", "[ $ ] [ word ]\n", 1);					//"\$" -> &
	test("\"\\\"\"", "[ \" ] [ word ]\n", 1);				//"\"" -> "
	test("\"\\`\"", "[ ` ] [ word ]\n", 1);					//"\`" -> `
	test("\"\\n\"", "[ \\n ] [ word ]\n", 1);				//"\n" -> \n
	test_error("\"\\", E_MISSING_SECOND_DOUBLE_QUOTE);		//
	test_error("\"\\\"", E_MISSING_SECOND_DOUBLE_QUOTE);	//"\"
	test_error("\"`\"", E_MISSING_SECOND_BACK_QUOTE);	//"`"
	test("\"\\1\"", "[ \\1 ] [ word ]\n", 1);				//"\1"
	test("\"\\\"\"", "[ \" ] [ word ]\n", 1);				//"\""
	
	test("q\\\"", "[ q\" ] [ word ]\n", 1);
	test("q\\'", "[ q' ] [ word ]\n", 1);
	test("\\q", "[ q ] [ word ]\n", 1);
	test("''1", "[ 1 ] [ io_number ]\n", 1);
	test("''", "", 0);
	test_error("'", E_MISSING_SECOND_SINGLE_QUOTE);
	test("1''", "[ 1 ] [ io_number ]\n", 1);
	test("'\"'", "[ \" ] [ word ]\n", 1);
	test("'\\$~\"'", "[ \\$~\" ] [ word ]\n", 1);			//'\$~"'	\$~"
	test_error("\"", E_MISSING_SECOND_DOUBLE_QUOTE);
	test("""", "", 0);
	test("\"\"", "", 0);
	test("<<-q", "[ <<- ] [ double_less_dash ]\n[ q ] [ word ]\n", 2);
	test("<<-", "[ <<- ] [ double_less_dash ]\n", 1);
	test("\\nq", "[ \\n ] [ newline ]\n[ q ] [ word ]\n", 2);
	test("\\n", "[ \\n ] [ newline ]\n", 1);
	test("q\\n", "[ q ] [ word ]\n[ \\n ] [ newline ]\n", 2);
	test("\\", "[ \\ ] [ word ]\n", 1);
	test("\\\"", "[ \" ] [ word ]\n", 1);
	test_error("", E_OK);
	test_error(NULL, E_NULL_INPUT);

	fdputs("lex:\tok\n", STDOUT_FILENO);
}