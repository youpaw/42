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
#define N_ESC_KEY_HANDLERS 11
#define INP_CH_FLAG 0
#define INP_BUILT_TABLE 1
#define INP_MAKING_CHOICE 2
#define FIRST_PROMPT_TEXT "42sh $> "
#define FIRST_PROMPT_LEN 8
#define NEXT_PROMPT_TEXT "> "
#define NEXT_PROMPT_LEN 2
#define N_BUILTINS 9
#define MAX_PATH 1024

# include <termios.h>
# include <stdint.h>
# include "cc_vec.h"
# include "cc_lst.h"
# include "cc_graph.h"
# include "lexer.h"

struct termios		g_tty_backup;

typedef struct		s_input
{
	t_vec			**line;					//array with letters of string
	size_t 			cursor_x_position;		//current position of cursor
	size_t 			cursor_y_position;		//current position of cursor
	size_t 			len;					//len of whole string
	size_t 			*line_len;				//len of line before newline
	char 			*hist_storage;
}					t_input;

typedef union		u_letter
{
	char			ch[5];
	int				num;
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
	enum s_predict_type type;
}				t_predict_token;

char 		*g_rd_history_storage;

void		tty_init(void);
void		tty_restore(void);
void		termcap_init(void);

void 		del_predict_token(t_predict_token **token);
t_predict_token *get_predict_token(char *raw);

void select_choise(void *files, t_input *inp, char *current);

void 		put_str_to_input(t_input *inp, char *part);

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
int			handle_down_arrow(t_input *inp);
int			handle_up_arrow(t_input *inp);
int			handle_home_key(t_input *inp);
int			handle_end_key(t_input *inp);

int			handle_key(char *key, t_input *input);

void 		handle_command_token(t_input *inp, t_predict_token *token);

t_input 	input_init(char *line);
int			readline(char **line);

void		clear_display_input(t_input *inp);
void		complete_print(t_input *input, t_list **to_print);
void		common_redraw(t_input *input);
void		redraw_input_adding(t_input *inp);
void		redraw_input_del(t_input *inp);

char *input_to_str(t_input input, int newline);
char		*input_to_n_str(t_input input);
int			get_displayed_symbol_len(unsigned char *num);

void		handle_file_token(t_input *input, t_predict_token *token, int access_mode);
void		handle_param_token(t_input *input, t_predict_token *token);
void		handle_choice_tab(t_input *input, t_list **options);

t_list		*get_list_files(char *path, char *name, int access_mode);
char		**get_filename(char *fullname);
int			check_for_utf8_comb_charecter(char *prev, char *letter, size_t len);
char 		*find_same_part(t_list *files, char*filename);
void		choose_token(t_input *input, t_list *lst);
void 		clear_last_disp_token(char *token, t_input *input);


void		signal_init(void);
void		signal_handler(int sig);

void 		print_prompt(t_input *inp);
char 		*get_prompt(int y);
int 		get_prompt_len(int y);

void		fill_complition_graph(t_graph *graph);

char		*restore_from_hist_storage(t_input *inp);
void		save_to_hist_storage(t_input *inp);


void put_str_to_input(t_input *inp, char *part);

void reload_input(t_input *inp, char *str);
void redraw_input(t_input inp, char *str);
void put_cursor_to_the_end(t_input *inp);

#endif //READLINE_H
