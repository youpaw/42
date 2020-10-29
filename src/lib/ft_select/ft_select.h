/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 16:15:55 by mgena             #+#    #+#             */
/*   Updated: 2020/08/16 14:50:47 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_ft_select_H
# define FT_SELECT_ft_select_H

# include <unistd.h>
# include <fcntl.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <stdbool.h>
# include <term.h>
# include <sys/stat.h>
# include "cc_lst.h"


#define N_SELECT_KEY_HANDLERS_COUNT 5

typedef struct	s_outputs
{
	char			*norm;
	char			*reverse_video;
	char			*hide_cursor;
	char			*show_cursor;
	char			*move_right;
	char			*move_down;
	int				fd;
	int 			cur_y_pos;
	bool			flag_lil_wnd;
	int 			engaged_space;
}				t_outputs;

typedef struct	s_selection
{
	char				*word;
	int					len;
	bool				selected;
	bool				under_cursor;
	int					vert_pos;
	int					hor_pos;
	struct s_selection	*next;
	struct s_selection	*prev;
}				t_selection;

typedef struct		s_key_select_handler{
	char			primary_key[5];
	int		(*handler)(t_selection**);
}					t_key_select_handler;

t_outputs		g_out;
t_selection 	*g_selection;

t_selection		*add_doubly_list(t_selection *lst, char *word, size_t len);
int				del_double_list_item(t_selection *lst);
char * select_args(t_selection *selections);
void			delete_elem(t_selection **selection);
void			del_selections(t_selection **selections);
void			draw_selections();
struct winsize	get_winsize(void);
void			tinit(void);
t_selection		*get_under_cursor(t_selection **selection);
int move_cursor_up(t_selection **selection);
int move_cursor_down(t_selection **selection);
int move_cursor_left(t_selection **selection);
int move_cursor_right(t_selection **selection);
void			select_init(void);
void			init_signals(void);
t_selection		*set_cursor_on_pos(t_selection *cpy, int fnd_hor, int fnd_vert);
int				check_winsize(int len);
void			restore_displayed(t_selection *selection);
void move_start();
t_selection *convert_list_2_selection(t_list *lst);
char *ft_select(t_selection *selections);

#endif
