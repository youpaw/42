//
// Created by Maxon Gena on 9/1/20.
//

#include "readline.h"

static unsigned int	max_lst_data_len(t_list *lst)
{
	unsigned int max_len;
	unsigned int len;

	max_len = 0;
	while (lst)
	{
		len = strlen(lst->content);
		if (len > max_len)
			max_len = len;
		lst = lst->next;
	}
	return (max_len);
}

typedef struct	s_table
{
	unsigned int colum_count;
	unsigned int line_count;
	unsigned int cell_size;
	char 		**table;
}				t_table;

static void strcpy_space(char *dst, char *src, unsigned int size)
{
	int i;

//	puts(src);
//	puts("\n");
//	sleep(1);
	i = 0;
	while (*src)
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	while (i != size)
	{
		*dst = ' ';
		i++;
		dst++;
	}
}

static void fill_table(t_table *table, t_list *lst)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (lst)
	{
		if (i != table->colum_count - 1)
			strcpy_space(&(table->table[k++][table->cell_size * i]), lst->content, table->cell_size);
		else
			strcpy(&(table->table[k++][table->cell_size * i]), lst->content);
		if (k == table->line_count)
		{
			k = 0;
			i++;
		}
		lst = lst->next;
	}
}


static void show_table(t_list *lst)
{
	struct winsize ws;
	int i;
	t_table table;

	i = 0;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
	table.cell_size = max_lst_data_len(lst) + 1;
	table.colum_count = ws.ws_col / table.cell_size;
	table.line_count = lst_get_size(lst) / table.colum_count;
	table.table = (char**)xmalloc(sizeof(char*) * table.line_count);
//	printf("%d\n\n", table.colum_count);
	while (i != table.line_count)
		table.table[i++] = xmalloc(sizeof(char) * table.colum_count * table.cell_size);
	fill_table(&table, lst);
	i = 0;
	while (i != table.line_count)
	{
		puts(table.table[i++]);
		putchar('\n');
	}
	restore_tty();
	exit(0);

}

void	choose_token(t_input *input, t_list *lst)
{
	tputs(tgetstr("sc", NULL), 1, putchar);
	tputs(tgetstr("do", NULL), 1, putchar);
	show_table(lst);
//	while (lst)
//	{
//		puts(lst->content);
//		lst = lst->next;
//		puts("\n");
//	}
	tputs(tgetstr("rc", NULL), 1, putchar);
	lst_del(&lst, NULL);
}