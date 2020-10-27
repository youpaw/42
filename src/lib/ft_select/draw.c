/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 14:49:09 by mgena             #+#    #+#             */
/*   Updated: 2020/08/16 19:04:42 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	set_colour_for_type(int fd, mode_t type)
{
	if (S_ISREG(type))
	{
		if (S_IXUSR & type)
			ft_fdprintf(fd, "{red}");
		return ;
	}
	else if (S_ISDIR(type))
	{
		if (S_ISVTX & type)
			ft_fdprintf(fd, "\e[102m\e[30m");
		else
			ft_fdprintf(fd, "{blue}");
	}
	else if (S_ISBLK(type))
		ft_fdprintf(fd, "\e[46m\e[94m");
	else if (S_ISCHR(type))
		ft_fdprintf(fd, "\e[43m\e[94m");
	else if (S_ISLNK(type))
		ft_fdprintf(fd, "{magnetic}");
	else if (S_ISSOCK(type))
		ft_fdprintf(fd, "{magnetic}");
}

void	draw_letters(t_selection *selection, int wide)
{
	if (selection->under_cursor)
		ft_putstr_fd(g_out.underline, g_out.fd);
	if (selection->selected)
		ft_putstr_fd(g_out.reverse_video, g_out.fd);
	set_colour_for_type(g_out.fd, selection->filetype);
	ft_fdprintf(g_out.fd, "%s{eoc}\e[49m", selection->word);
	ft_putstr_fd(g_out.norm, g_out.fd);
	while ((wide - selection->len - 1) != 0)
	{
		ft_putstr_fd(g_out.move_right, g_out.fd);
		wide--;
	}
}

void	draw_word(t_selection *selection, int *cur, int cn)
{
	draw_letters(selection, (get_winsize().ws_col / cn));
	selection->vert_pos = cur[0];
	selection->hor_pos = cur[1];
	(cur[1])++;
	if (cur[1] == cn)
	{
		ft_putstr_fd(g_out.move_down, g_out.fd);
		cur[1] = 0;
		(cur[0])++;
	}
	else
		ft_fdprintf(g_out.fd, " ");
}

int		get_max_words_len(t_selection *selection)
{
	t_selection	*first;
	int			max_len;

	max_len = selection->len;
	first = selection;
	selection = selection->next;
	while (selection != first)
	{
		if (selection->len > max_len)
			max_len = selection->len;
		selection = selection->next;
	}
	return (max_len > 2 ? max_len : 3);
}

void	draw_selections(void)
{
	t_selection *selection;
	t_selection *first;
	int			column_num;
	int			cur[2];

	selection = selection_storage(NULL);
	restore_displayed(selection);
	ft_bzero(cur, sizeof(int) * 2);
	if (!(column_num = check_winsize(get_max_words_len(selection))))
		return ;
	first = selection;
	draw_word(selection, cur, column_num);
	selection = selection->next;
	while (first != selection)
	{
		if (cur[0] == get_winsize().ws_row - 1)
			break ;
		draw_word(selection, cur, column_num);
		selection = selection->next;
	}
}
