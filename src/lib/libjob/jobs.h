//
// Created by Azzak Omega on 9/22/20.
//

#ifndef JOBS_H
# define JOBS_H
#include <termios.h>
#include <stddef.h>
#include "lexer.h"
#include "parser.h"
# define N_BUILTINS 14
# define JOB_VEC_CAPACITY 15

extern pid_t			g_pgid;
extern struct termios	g_tmodes;
extern int				g_terminal;
extern int				g_is_interactive;
extern int 				g_has_job_control;
extern int 				g_can_exit;
extern t_vec			*g_job_queue;

typedef struct	s_process
{
	struct s_process *next;
	t_ast *ast;
	char **argv;
	char **env;
	pid_t pid;
	char completed;
	char stopped;
	int status;
	int stdin;
	int	stdout;
	int	stderr;
}				t_process;

typedef struct s_job
{
	struct s_job 	*next;
	char 			*command;
	t_process 		*first_process;
	pid_t 			pgid;
	int				index;
	char			notified;
	int 			is_fg;
	struct termios	tmodes;
} t_job;

extern	t_job	*g_first_job;

typedef enum	e_job_print_mode
{
	JPM_DEFAULT = 1,
	JPM_PID,
	JPM_LONG,
	JPM_BG
}				t_job_print_mode;



/*
** Job management
*/

void	jobs_init(void);
t_job	*job_new(int is_foreground);
int		get_new_job_index(void);
int		push_job(t_job *job);
int		launch_job(t_job *job, int is_foreground, int is_forked);
void	continue_job(t_job *j, int is_foreground);
int		put_job_in_foreground (t_job *j, int cont);
void	put_job_in_background (t_job *j, int cont);
void	mark_job_as_running(t_job *j);
void	update_status(void);
void	do_job_notification(void);
int		wait_for_job_complete(t_job *j);
int		wait_for_job(t_job *j, int options);
int		job_is_stopped (t_job *j);
int		job_is_completed (t_job *j);
t_job	*find_job_by_index(int index);
void	remove_job_by_index(int job_index);

/*
** Processes management
*/

t_process	*process_new(void);
int 	process_init(t_process *p);
void	fork_and_launch_processes(t_job *job, int is_foreground);
void	launch_process (t_process *p, pid_t pgid, int is_foreground);
int		mark_process_status (pid_t pid, int status);
int		get_last_process_status(t_process *p);

/*
** Job builtins
*/

int		run_builtin_or_hash(t_process *process);
int		get_builtin_index(const char *name);
int 	exec_builtin_by_index(const char **av, int index);

void	exit_shell(int exit_code);
int		exit_builtin(const char **av);
int		jobs(const char **av);
int		fg_builtin(const char **av);
int		bg_builtin(const char **av);
int		bg_fg(const char **av, int is_foreground);
int		type(const char **av);

/*
** Job queue
*/

void	queue_push_back(int index);
void	queue_remove(int index);
void	queue_move_back(int index);
int		queue_get_current(int is_job_builtin);
int		queue_get_last(int is_job_builtin);
int		queue_get_job_index_by_str(const char *str);

/*
** Job print functions
*/

void    print_job_pid(t_job *job);
void	print_job_status_str(t_job *job);
void    print_job_formatted(t_job *job, int is_job_builtin, t_job_print_mode mode);
char	get_status_sign_for_job(int job_index, int is_job_builtin);
char	*get_status_message(int status);

/*
** Signals
*/

void	ignore_job_and_interactive_signals(void);
void	restore_job_and_interactive_signals(void);

/*
** Free functions
*/

void	free_job(t_job **j);
void	free_all_jobs(void);
void	free_processes(t_process *p);

/*
** Redirects
*/

char	**get_args(t_ast *ast);
t_ast	**get_redirect_nodes(t_ast *ast);
int		expand_ast(t_ast *ast);
void	prepare_exec_env(t_ast *ast);
int		is_standard_io(int fd);
int		is_minus(t_ast *leafs);
int		set_redirects(t_process *p);
int		redirect_close_stdio(t_process *process, int from);
void	redirect_init_process_file(t_process *process, int from, int to);
int		redirect_print_error(int errcode, const char *token);
int		redirect_parse_right_side(t_token *token, int open_options,
									int can_be_number, int is_maybe_minus);
int		redirect_parse_left_side(t_ast *leafs, int default_value);
int		redirect_great_and(t_ast *leafs, t_process *process);
int		redirect_less_and(t_ast *leafs, t_process *process);
int		redirect_less_and_right_side(t_ast *leafs);
int		redirect_great(t_ast *leafs, t_process *process, int is_double_great);
int		redirect_less(t_ast *leafs, t_process *process);
int		redirect_heredoc(t_ast *leafs, t_process *process);
int		prepare_redirect(t_ast *ast, t_process *process);

#endif
