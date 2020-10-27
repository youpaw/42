/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 16:15:55 by mgena             #+#    #+#             */
/*   Updated: 2020/08/16 14:50:47 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_HEADER_H
# define FT_SELECT_HEADER_H

# include <unistd.h>
# include <fcntl.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <stdbool.h>
# include <term.h>
# include <sys/stat.h>

typedef struct	s_outputs
{
	struct termios	savetty;
	char			tbuf[2048];
	char			strings[256];
	char			*p;
	char			*tname;
	char			*clear;
	char			*clear_after;
	char			*underline;
	char			*norm;
	char			*reverse_video;
	char			*hide_cursor;
	char			*show_cursor;
	char			*move_start;
	char			*move_right;
	char			*move_down;
	int				fd;
	bool			flag_lil_wnd;
}				t_outputs;

typedef struct	s_selection
{
	char				*word;
	int					len;
	mode_t				filetype;
	bool				selected;
	bool				under_cursor;
	int					vert_pos;
	int					hor_pos;
	struct s_selection	*next;
	struct s_selection	*prev;
}				t_selection;

t_outputs		g_out;

t_selection		*add_doubly_list(t_selection *lst, char *word, size_t len);
int				del_double_list_item(t_selection *lst);
char			*select_args(t_selection *selections);
void			delete_elem(t_selection **selection);
void			draw_selections();
struct winsize	get_winsize(void);
void			escape(void);
void			tinit(void);
t_selection		*selection_storage(t_selection *obj);
mode_t			get_filetype(char *word);
t_selection		*get_under_cursor(t_selection **selection);
void			move_cursor_up(t_selection **selection);
void			move_cursor_down(t_selection **selection);
void			move_cursor_left(t_selection **selection);
void			move_cursor_right(t_selection **selection);
void			return_tty(void);
void			main_init(void);
void			sighandler(int sig);
void			init_signals(void);
t_selection		*set_cursor_on_pos(t_selection *cpy, int fnd_hor, int fnd_vert);
char			*get_args_array(t_selection *selection);
int				check_winsize(int len);
void			restore_displayed(t_selection *selection);

#endif
