#include "cc.h"
#include "expand.h"
#include <stdio.h>
#include "readline.h"

#include "env.h"
#include "cc_lst.h"
#include "alias.h"

void print_list(t_list *lst)
{
	putendl(lst->content);
}

void del_str(void *item)
{
	return ;
	free(item);
}
int main(int ac, char *av[], char *en[])
{
	alias_init();
	alias_add("ls=ls -a");
	alias_add("ls 1=ls -2a");
	alias_add("ls		2=ls -2a");
	alias_add("ls		2=ls -2a");
	alias_add("ls22=ls -a");
	alias_add("abd=lsgaw");
	alias_add("ab=");
	putendl(alias_get_value("ls22"));
	alias_remove("ls22");
	//putendl(alias_get_value("ls22"));
	alias_print();
	alias_del();

	return (0);
}

/*
int main(int ac, char *av[], char *en[])
{

	av_init(av[0], &av[1]);
	putendl(av_get(0));
	putendl(av_get(1));
	putendl(av_get(5));
	return (0);
}
*/
/*
int main(int ac, char *av[], char *en[])
{
	char **exec_str;

	env_init((const char **)en);
//	putendl("\n\nGLOBAL\n\n");
//	env_print_global();
//	putendl("\n\nFULL\n\n");
//	env_print_full();
	//putnbr(hash_map_get_size(g_env));
	//env_print_global();
	exec_env_init();
	exec_env_insert("HOME=home");
	//exec_env_insert("PATH=home");
	exec_env_insert("myvar=home");
	exec_str = exec_env_2array();
	arr2_quick_sort((void **)exec_str, 0, arr2_get_size(exec_str) - 1,
					(int (*)(const void *, const void *))strcmp);
	arr2_print(exec_str, NULL, NULL);
	arr2_del(exec_str);
	free(exec_str);
	exec_env_del();
	env_del();
	return (0);
}

*/
/*
int main(int ac, char *av[], char *en[])
{
	t_letter res;

	tty_init();
	char *line = NULL;
	if (ac == 2)
	{
		if (strcmp(av[1], "-c") == 0)
		{
			res.num = getch();
			write(STDOUT_FILENO, &res.ch, 4);
			printf("\n\\%o, \\%o, \\%o, \\%o, %d", res.ch[0], res.ch[1], res.ch[2], res.ch[3], res.num);
			restore_tty();
			return (0);
		}
	}
	readline(&line);
	restore_tty();
	return (0);
}
 */
/*
 * int main(int ac, char *av[], char *en[])
{
	t_list *lst;
	int 	result;


	lst = lst_new("0", sizeof(char) * 2);
	lst_add(&lst, lst_new("a", sizeof(char) * 2));
	lst_add(&lst, lst_new("b", sizeof(char) * 2));
	lst_add(&lst, lst_new("c", sizeof(char) * 2));
	result = lst_del_one_if(&lst, "c", strcmp, del_str);
	putnbr(result);
	lst_iter(lst, print_list);
	lst_del(&lst, del_str);
	//putendl("start");
	//print_str_arr(en);
	//env_init(en);
	//print_env();
	//print_full_env();
	//putendl("end");
	return (0);
}
*/

/*
static void                     print_str_matrix(const char **args, char *sep)
{
	if (args)
	{
		while (*args)
		{
			puts(sep);
			puts(*args);
			putendl(sep);
			args++;
		}
	}
}

static void                     free_matrix(char **m)
{
	if (m)
		while (*m)
			free(*m++);
}

void    print(t_list *l)
{
	t_graph *g = l->content;

	putchar(g->symbol);
	putchar(' ');
	putnbr(g->index);
	putchar('\n');
}

int             main(void)
{
	t_graph *g;
	t_graph *f;
	char    **m;

	g = graph_new('\0', 0);
	graph_insert(g, "ab");
	graph_insert(g, "afcd");
	graph_insert(g, "abcffg");
	graph_insert(g, "abed");
	graph_insert(g, "abd");
	graph_insert(g, "svbabcd");
	graph_insert(g, "gsbcd");
	graph_insert(g, "gsbcafgsd");
	putendl("\n\n\n");
	m = graph_get_names(g, "");
	print_str_matrix((const char **)m, "|");
	free_matrix(m);
	free(m);

	graph_del(g);
	free(g);
	return (0);
}
 */