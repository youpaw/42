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

#define N_ORD_KEY_HANDLERS 6
#define N_ESC_KEY_HANDLERS 9
#define INP_CH_FLAG 0
#define INP_BUILT_TABLE 1
#define INP_MAKING_CHOICE 2
#define PROMPT_TEXT "42sh $> "
#define PROMPT_LEN 8

# include <termios.h>
#include <stdint.h>
#include "ft_select.h"
# include "cc_vec.h"
# include "cc_lst.h"
# include "lexer.h"

struct termios		g_tty_backup;
char g_prompt[PROMPT_LEN + 1];

typedef struct		s_input
{
	t_vec			**line;
	int				cursor_x_position;
	int				cursor_y_position;
	size_t 			len;
	int				*line_len;
	int 			indent;
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

typedef struct		s_key_readline_handler{
	char			primary_key[5];
	int				(*handler)(t_input *);
}					t_key_readline_handler;

typedef enum s_predict_type{
	r_cmd,
	r_file,
	r_param
}				t_predict_type;

typedef  struct s_predict_token
{
	char 		*raw;
	size_t		original_len;
	enum s_predict_type type;
}				t_predict_token;

int 		g_input_state_flag;

void		tty_init(void);
void		tty_restore(void);
void		termcap_init(void);

void 		del_predict_token(t_predict_token **token);
t_predict_token *get_predict_token(char *raw, size_t len);

void 		select_choise(t_selection *files, t_input *inp);

void put_str_to_inp(t_input *input, char *part);

int			handle_left_arrow(t_input *inp);
int			handle_right_arrow(t_input *inp);
int			handle_shift_up(t_input *inp);
int			handle_shift_down(t_input *inp);
int			handle_shift_right(t_input *inp);
int			handle_shift_left(t_input *inp);
int			handle_backspace(t_input *inp);
int			handle_del(t_input *inp);
int			handle_tab(t_input *inp);
int 		handle_symbol_key(t_input *inp, char *key);
int			handle_escape_sequence(t_input *input);

int			handle_key(char *key, t_input *input);

t_input 	input_init(char *line);
int			readline(char **line);

void		complete_print(t_input *input, t_list **to_print);
void		common_redraw(t_input *input);
void		redraw_input_adding(t_input *inp);
void		redraw_input_del(t_input *inp);

char		*input_to_str(t_input input);
int			get_displayed_symbol_len(unsigned char *num);
void 		handle_file_token(t_input *input, t_predict_token *token);
void handle_choice_tab(t_input *input, t_list **options);
char *find_same_part(t_list *files, char*filename);
void		choose_token(t_input *input, t_list *lst);


void		signal_init(void);
void		signal_handler(int sig);

void 	print_prompt(t_input *inp);

#endif //READLINE_H
