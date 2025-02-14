/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallist <fmallist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:54:42 by fmallist          #+#    #+#             */
/*   Updated: 2020/11/10 15:59:49 by fmallist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <unistd.h>
# include <fcntl.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <stdbool.h>
# include <term.h>
# include <sys/stat.h>
# include "cc_lst.h"

# define N_SELECT_KEY_HANDL_C 5

typedef struct	s_outputs
{
	char			*norm;
	char			*reverse_video;
	char			*hide_cursor;
	char			*show_cursor;
	char			*move_right;
	char			*move_down;
	int				fd;
	int				cur_y_pos;
	bool			flag_lil_wnd;
	bool			flag_sigwinch;
	int				engaged_space;
}				t_outputs;

typedef struct	s_selection
{
	char				*word;
	size_t				cstring_len;
	size_t				display_len;
	bool				selected;
	bool				under_cursor;
	int					vert_pos;
	int					hor_pos;
	struct s_selection	*next;
	struct s_selection	*prev;
}				t_selection;

typedef struct	s_key_select_handler{
	char			primary_key[5];
	int				(*handler)(t_selection**);
}				t_key_select_handler;

t_outputs		g_out;
t_selection		*g_selection;

t_selection		*add_doubly_list(t_selection *lst, char *word, size_t len);
int				del_double_list_item(t_selection *lst);
char			*select_args(t_selection *selections);
void			delete_lst(t_selection **selection);
void			set_term_str(void);
void			draw_selections();
struct winsize	get_winsize(void);
void			tinit(void);
t_selection		*get_under_cursor(t_selection **selection);
int				move_cursor_up(t_selection **selection);
int				move_cursor_down(t_selection **selection);
int				move_cursor_left(t_selection **selection);
int				move_cursor_right(t_selection **selection);
void			select_init(void);
void			init_signals(void);
t_selection		*set_cursor_on_pos(t_selection *cpy, int fnd_hor, int fnd_vert);
int				check_winsize(int len);
void			restore_displayed(t_selection *selection);
void			move_start();
t_selection		*convert_list_2_selection(t_list *lst);
t_selection		*convert_array_2_selection(char **argv);
char			*ft_select(t_selection *selections);

#endif
