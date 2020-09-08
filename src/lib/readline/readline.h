/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgena <mgena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 16:20:02 by mgena             #+#    #+#             */
/*   Updated: 2020/08/28 14:20:11 by mgena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
#define READLINE_H
#define N_ORD_KEY_HANDLERS 7
#define N_ESC_KEY_HANDLERS 7

# include <termios.h>
# include "cc_vec.h"
# include "cc_lst.h"
# include "lexer.h"

struct termios		g_tty_backup;

typedef struct		s_input
{
	t_vec			**line;
	int				cursor_x_position;
	int				cursor_y_position;
	size_t 			len;
	int				*line_len;
}					t_input;

typedef union		u_letter
{
	char			ch[5];
	unsigned char	uch[5];
	int				num;
	unsigned int	unum;
}					t_letter;

/*
 * Struct to easy converting UTF-8. It uses space in memory like this:
*				  mask        lead        beg      end       bits
*        &(utf_t){0b00111111, 0b10000000, 0,       0,        6    }
*/
typedef struct {
	char			mask;
	char			lead;
	uint32_t		beg;
	uint32_t		end;
	int				bits_stored;
}					utf_t;

typedef struct		s_key_handler{
	char			primary_key[5];
//	char			secondary_key[5];
	int				(*handler)(t_input *);
}					t_key_handler;

int 		g_input_changed_flg;

void		tty_init(void);
void		tty_restore(void);
void		termcap_init(void);

int			handle_left_arrow(t_input *inp);
int			handle_right_arrow(t_input *inp);
int			handle_shift_up(t_input *inp);
int			handle_shift_down(t_input *inp);
int			handle_backspace(t_input *inp);
int			handle_del(t_input *inp);
int			handle_tab(t_input *inp);
int 		handle_symbol_key(t_input *inp, char *key);
int			handle_escape_sequence(t_input *input);

int			handle_key(char *key, t_input *input);

t_input 	input_init(char *line);
int			readline(char **line);

void		complete_print(t_input *input, t_list **to_print);
char		*input_to_str(t_vec *input, int len);
int			get_displayed_symbol_len(unsigned char *num);
t_list		*get_list_files(t_input *input, t_token *token);
void		choose_token(t_input *input, t_list *lst);


void		signal_init(void);
void		signal_handler(int sig);

#endif //READLINE_H
