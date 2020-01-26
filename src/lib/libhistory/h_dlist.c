/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 13:00:51 by darugula          #+#    #+#             */
/*   Updated: 2020/01/01 13:00:52 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
Int get_prev(char *out) - при первичном вызове вернёт строку с последней записанной командой, при повторном вызове вернёт предпоследнюю команду и т.д.если дошел до первой команды строку зануляет и возвращает код ошибки .
Int get_next(const char *out) аналогично, но в другую сторону.
Int write_to_history(const char *command) - принимает команду и дописывает ее в конец файла инициализации.
void get_reset() - сбрасывает счётчик и при последующем вызове команд get * они будут работать с самого начала.*/
#include "cc.h"
#include "lists.h"

t_d_list *g_head = NULL;
t_d_list *g_current = NULL;
t_d_list *g_last = NULL;


void		h_append(const char *content)
{
	t_d_list *l;

	int *q = malloc(1000);
	free(q);
	l = NULL;
	l = dlst_new(strdup(content), -1);
	l->prev = g_last;
	if (g_last == NULL)
	{
		g_last = l;
		g_head = l;
		return;
	}
	g_last->list.next = (t_list *)l;
	g_last = l;
	g_current = NULL;
}

void		h_free(void)
{
	if (g_head == NULL)
	{
		return;
	}
	lst_free((t_list **)&g_head);
	g_last = NULL;
	g_current = NULL;
	if (g_head != NULL)
	{
		//debug_printf("g_head != NULL\n");
		exit(1);
	}
}

t_d_list *h_get_head()
{
	return (g_head);
}