# **************************************************************************** #
# GENERIC_VARIABLES

OBJ_DIR = build

# **************************************************************************** #
# COMPILER_OPTIONS

C_COMPILER = gcc
C_STANDART = 
C_CFLAGS =  $(CFLAGS) $(CPPFLAGS)
C_LFLAGS =  $(CFLAGS) $(CPPFLAGS)

# **************************************************************************** #
# FT_SELECT TARGET DESCRIPTION

FT_SELECT_NAME = ft_select
FT_SELECT_PATH = src/lib/ft_select
FT_SELECT_FILE = ./libft_select.a
FT_SELECT_SRCS = cursor.c cursor_more.c draw.c ft_select.c init_and_signals.c select_args.c support_1.c get_winsize.c support_3.c termcap_extra.c two_side_list.c
FT_SELECT_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(FT_SELECT_SRCS))
FT_SELECT_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(FT_SELECT_SRCS))
FT_SELECT_LIBS = 
FT_SELECT_INCS = -I src/lib/ft_select -I src/lib/libcc/list -I src/lib/libcc/char -I src/lib/libcc/string -I src/lib/libcc/memory -I src/lib/libcc/num

# **************************************************************************** #
# CC_OPTPARSE TARGET DESCRIPTION

CC_OPTPARSE_NAME = cc_optparse
CC_OPTPARSE_PATH = src/lib/libcc/optparse
CC_OPTPARSE_FILE = ./libcc_optparse.a
CC_OPTPARSE_SRCS = optparse.c print_usage.c
CC_OPTPARSE_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(CC_OPTPARSE_SRCS))
CC_OPTPARSE_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(CC_OPTPARSE_SRCS))
CC_OPTPARSE_LIBS = 
CC_OPTPARSE_INCS = -I src/lib/libcc -I src/lib/libcc/optparse -I src/lib/libcc/string

# **************************************************************************** #
# BUILTIN_CD TARGET DESCRIPTION

BUILTIN_CD_NAME = builtin_cd
BUILTIN_CD_PATH = src/lib/builtins/cd
BUILTIN_CD_FILE = ./libbuiltin_cd.a
BUILTIN_CD_SRCS = cd.c cd_check_opt.c cd_error_print.c cd_path_canonization.c cd_path_validation.c
BUILTIN_CD_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(BUILTIN_CD_SRCS))
BUILTIN_CD_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(BUILTIN_CD_SRCS))
BUILTIN_CD_LIBS = 
BUILTIN_CD_INCS = -I src/lib/builtins/ -I src/lib/builtins/cd -I src/lib/libcc -I src/lib/libcc/list -I src/lib/libenv -I src/lib/libcc/hash_map -I src/lib/libcc/graph -I src/lib/libcc/optparse -I src/lib/liberror -I src/lib/libcc/memory -I src/lib/libcc/string

# **************************************************************************** #
# CC TARGET DESCRIPTION

CC_NAME = cc
CC_PATH = src/lib/libcc/graph
CC_FILE = ./libcc.a
CC_SRCS = graph_cmp.c graph_del.c graph_get_names.c graph_get_suffixes.c graph_init.c graph_insert.c graph_new.c
CC_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(CC_SRCS))
CC_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(CC_SRCS))
CC_LIBS = 
CC_INCS = -I src/lib/libcc -I src/lib/libcc/graph -I src/lib/libcc/list -I src/lib/libcc/string -I src/lib/libcc/memory

# **************************************************************************** #
# PARSER TARGET DESCRIPTION

PARSER_NAME = parser
PARSER_PATH = src/lib/libparse
PARSER_FILE = ./libparser.a
PARSER_SRCS = del_ast.c get_node_token.c new_ast_node.c node_and_or.c node_cmd_prefix.c node_cmd_suffix.c node_complete_cmd.c node_filename.c node_here_end.c node_io_file.c node_io_here.c node_io_redirect.c node_list.c node_pipe_seq.c node_pipeline.c node_simple_cmd.c parse.c
PARSER_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(PARSER_SRCS))
PARSER_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(PARSER_SRCS))
PARSER_LIBS = 
PARSER_INCS = -I src/lib/libparse -I src/lib/liblex -I src/lib/libcc/vector -I src/lib/liberror -I src/lib/libcc -I src/lib/libcc/list -I src/lib/libenv -I src/lib/libcc/hash_map -I src/lib/libcc/graph

# **************************************************************************** #
# CC_REGEX TARGET DESCRIPTION

CC_REGEX_NAME = cc_regex
CC_REGEX_PATH = src/lib/libcc/regex
CC_REGEX_FILE = ./libcc_regex.a
CC_REGEX_SRCS = match.c nmatch.c
CC_REGEX_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(CC_REGEX_SRCS))
CC_REGEX_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(CC_REGEX_SRCS))
CC_REGEX_LIBS = 
CC_REGEX_INCS = -I src/lib/libcc -I src/lib/libcc/regex

# **************************************************************************** #
# CC_FILE TARGET DESCRIPTION

CC_FILE_NAME = cc_file
CC_FILE_PATH = src/lib/libcc/file
CC_FILE_FILE = ./libcc_file.a
CC_FILE_SRCS = get_next_line.c
CC_FILE_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(CC_FILE_SRCS))
CC_FILE_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(CC_FILE_SRCS))
CC_FILE_LIBS = 
CC_FILE_INCS = -I src/lib/libcc -I src/lib/libcc/file -I src/lib/libcc/avl -I src/lib/libcc/string -I src/lib/libcc/memory

# **************************************************************************** #
# JOBS TARGET DESCRIPTION

JOBS_NAME = jobs
JOBS_PATH = src/lib/libjob
JOBS_FILE = ./libjobs.a
JOBS_SRCS = continue_job.c do_job_notification.c exec_builtin_by_index.c free_job.c find_job_by_index.c fork_and_launch_processes.c free_all_jobs.c free_processes.c get_args.c get_builtin_index.c get_last_process_status.c get_new_job_index.c get_redirect_nodes.c get_status_message.c get_status_sign_for_job.c handle_assignments.c is_minus.c is_standard_io.c job_is_completed.c job_is_stopped.c job_new.c jobs_init.c launch_job.c launch_process.c mark_job_as_running.c mark_process_status.c prepare_exec_env.c prepare_redirect.c print_job_formatted.c print_job_pid.c print_job_status_str.c process_init.c process_new.c push_job.c put_job_in_background.c put_job_in_foreground.c redirect_close_stdio.c redirect_great.c redirect_great_and.c redirect_heredoc.c redirect_init_process_file.c redirect_less.c redirect_less_and.c redirect_less_and_right_side.c redirect_parse_left_side.c redirect_parse_right_side.c redirect_print_error.c remove_job.c run_builtin.c run_builtin_by_index.c run_builtin_or_hash.c set_default_pipe_fds.c set_redirects.c signal_handlers.c update_status.c wait_for_job.c wait_for_job_complete.c
JOBS_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(JOBS_SRCS))
JOBS_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(JOBS_SRCS))
JOBS_LIBS = 
JOBS_INCS = -I src/lib/libjob -I src/lib/liblex -I src/lib/libcc/vector -I src/lib/liberror -I src/lib/libparse -I src/lib/builtins -I src/lib/libcc/string -I src/lib/libenv -I src/lib/libcc/hash_map -I src/lib/libcc/list -I src/lib/libcc/graph -I src/lib/libcc/memory -I src/lib/libhash -I src/lib/libexec -I src/lib/libcc/num

# **************************************************************************** #
# CC_AVL TARGET DESCRIPTION

CC_AVL_NAME = cc_avl
CC_AVL_PATH = src/lib/libcc/avl
CC_AVL_FILE = ./libcc_avl.a
CC_AVL_SRCS = avl_del.c avl_balance.c avl_del_one.c avl_get.c avl_get_height.c avl_get_pair.c avl_get_val.c avl_insert.c avl_map_infix.c avl_map_postfix.c avl_map_prefix.c avl_new.c avl_new_node.c
CC_AVL_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(CC_AVL_SRCS))
CC_AVL_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(CC_AVL_SRCS))
CC_AVL_LIBS = 
CC_AVL_INCS = -I src/lib/libcc -I src/lib/libcc/avl -I src/lib/libcc/math -I src/lib/libcc/memory

# **************************************************************************** #
# CC_SORT TARGET DESCRIPTION

CC_SORT_NAME = cc_sort
CC_SORT_PATH = src/lib/libcc/sort
CC_SORT_FILE = ./libcc_sort.a
CC_SORT_SRCS = quick_sort.c
CC_SORT_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(CC_SORT_SRCS))
CC_SORT_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(CC_SORT_SRCS))
CC_SORT_LIBS = 
CC_SORT_INCS = -I src/lib/libcc -I src/lib/libcc/sort

# **************************************************************************** #
# EXEC TARGET DESCRIPTION

EXEC_NAME = exec
EXEC_PATH = src/lib/libexec
EXEC_FILE = ./libexec.a
EXEC_SRCS = exec.c exec_and_or.c exec_complete_cmd.c exec_list.c exec_pipe_seq.c exec_pipeline.c exec_simple_cmd.c expand_ast.c get_command.c
EXEC_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(EXEC_SRCS))
EXEC_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(EXEC_SRCS))
EXEC_LIBS = 
EXEC_INCS = -I src/lib/libexec -I src/lib/libparse -I src/lib/liblex -I src/lib/libcc/vector -I src/lib/liberror -I src/lib/libenv -I src/lib/libcc/hash_map -I src/lib/libcc/list -I src/lib/libcc/graph -I src/lib/libjob -I src/lib/libcc/string

# **************************************************************************** #
# BUILTIN_ECHO TARGET DESCRIPTION

BUILTIN_ECHO_NAME = builtin_echo
BUILTIN_ECHO_PATH = src/lib/builtins/echo
BUILTIN_ECHO_FILE = ./libbuiltin_echo.a
BUILTIN_ECHO_SRCS = echo.c handle_esc_chars.c
BUILTIN_ECHO_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(BUILTIN_ECHO_SRCS))
BUILTIN_ECHO_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(BUILTIN_ECHO_SRCS))
BUILTIN_ECHO_LIBS = 
BUILTIN_ECHO_INCS = -I src/lib/builtins -I src/lib/builtins/alias -I src/lib/builtins/cd -I src/lib/builtins/echo -I src/lib/builtins/env -I src/lib/libcc -I src/lib/libcc/list -I src/lib/libcc/optparse -I src/lib/liberror -I src/lib/libcc/string -I src/lib/libcc/char

# **************************************************************************** #
# CC_LIST TARGET DESCRIPTION

CC_LIST_NAME = cc_list
CC_LIST_PATH = src/lib/libcc/list
CC_LIST_FILE = ./libcc_list.a
CC_LIST_SRCS = lst_add.c lst_add_sort.c lst_circle.c lst_del.c lst_del_circle.c lst_del_one.c lst_del_one_if.c lst_find.c lst_get_size.c lst_iter.c lst_map.c lst_new.c
CC_LIST_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(CC_LIST_SRCS))
CC_LIST_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(CC_LIST_SRCS))
CC_LIST_LIBS = 
CC_LIST_INCS = -I src/lib/libcc -I src/lib/libcc/list -I src/lib/libcc/memory

# **************************************************************************** #
# CC_MATH TARGET DESCRIPTION

CC_MATH_NAME = cc_math
CC_MATH_PATH = src/lib/libcc/math
CC_MATH_FILE = ./libcc_math.a
CC_MATH_SRCS = max.c min.c
CC_MATH_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(CC_MATH_SRCS))
CC_MATH_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(CC_MATH_SRCS))
CC_MATH_LIBS = 
CC_MATH_INCS = -I src/lib/libcc -I src/lib/libcc/math

# **************************************************************************** #
# CC_CHAR TARGET DESCRIPTION

CC_CHAR_NAME = cc_char
CC_CHAR_PATH = src/lib/libcc/char
CC_CHAR_FILE = ./libcc_char.a
CC_CHAR_SRCS = fdputchar.c getch.c isalnum.c isalpha.c isascii.c isdigit.c islower.c isprint.c isspace.c isupper.c iswspace.c putchar.c tolower.c toupper.c utf8_sizeof_symbol.c
CC_CHAR_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(CC_CHAR_SRCS))
CC_CHAR_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(CC_CHAR_SRCS))
CC_CHAR_LIBS = 
CC_CHAR_INCS = -I src/lib/libcc -I src/lib/libcc/char -I src/lib/libcc/memory -I src/lib/libcc/string

# **************************************************************************** #
# ENV TARGET DESCRIPTION

ENV_NAME = env
ENV_PATH = src/lib/libenv
ENV_FILE = ./libenv.a
ENV_SRCS = av_del.c av_get.c av_init.c env_cmp_pair.c env_del.c env_del_pair.c env_export.c env_get_value.c env_init.c env_insert_to.c env_print_full.c env_print_global.c env_print_pair.c env_remove_from.c env_update.c exec_env_2array.c exec_env_del.c exec_env_get_value.c exec_env_init.c exec_env_insert.c fill_graph_by_env_names.c get_env_names_sorted.c get_valid_name_length.c get_valid_name_length_no_check.c
ENV_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(ENV_SRCS))
ENV_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(ENV_SRCS))
ENV_LIBS = 
ENV_INCS = -I src/lib/libenv -I src/lib/libcc/hash_map -I src/lib/libcc/list -I src/lib/libcc/graph -I src/lib/libcc/string -I src/lib/libcc/memory -I src/lib/libcc/sort -I src/lib/libcc/char

# **************************************************************************** #
# CC_VECTOR TARGET DESCRIPTION

CC_VECTOR_NAME = cc_vector
CC_VECTOR_PATH = src/lib/libcc/vector
CC_VECTOR_FILE = ./libcc_vector.a
CC_VECTOR_SRCS = vec_del.c vec_del_one.c vec_get_at.c vec_get_last.c vec_new.c vec_pop.c vec_push.c vec_push_at.c vec_rm_at.c vec_rm_last.c
CC_VECTOR_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(CC_VECTOR_SRCS))
CC_VECTOR_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(CC_VECTOR_SRCS))
CC_VECTOR_LIBS = 
CC_VECTOR_INCS = -I src/lib/libcc -I src/lib/libcc/vector -I src/lib/libcc/memory

# **************************************************************************** #
# CALC TARGET DESCRIPTION

CALC_NAME = calc
CALC_PATH = src/lib/libcalc
CALC_FILE = ./libcalc.a
CALC_SRCS = calc.c calc_convert_to_postfix.c calc_evaluate.c calc_get_number.c calc_get_operator.c calc_get_priority.c calc_get_token.c calc_is_binary.c calc_is_forbidden.c calc_is_operator.c calc_is_unary.c calc_operate.c calc_operate_add.c calc_operate_and.c calc_operate_div.c calc_operate_eql.c calc_operate_goe.c calc_operate_grt.c calc_operate_les.c calc_operate_loe.c calc_operate_mlt.c calc_operate_mod.c calc_operate_neq.c calc_operate_or.c calc_operate_sub.c calc_state_number.c calc_state_operator.c calc_tokenize.c
CALC_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(CALC_SRCS))
CALC_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(CALC_SRCS))
CALC_LIBS = 
CALC_INCS = -I src/lib/libcalc -I src/lib/libcc/vector -I src/lib/libcc/string -I src/lib/liberror -I src/lib/libcc/num -I src/lib/libcc/char

# **************************************************************************** #
# CC_NUM TARGET DESCRIPTION

CC_NUM_NAME = cc_num
CC_NUM_PATH = src/lib/libcc/num
CC_NUM_FILE = ./libcc_num.a
CC_NUM_SRCS = atoi.c atoll.c fdputnbr.c numlen.c numlen_base.c putnbr.c
CC_NUM_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(CC_NUM_SRCS))
CC_NUM_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(CC_NUM_SRCS))
CC_NUM_LIBS = 
CC_NUM_INCS = -I src/lib/libcc -I src/lib/libcc/num -I src/lib/libcc/char

# **************************************************************************** #
# BUILTIN_ENV TARGET DESCRIPTION

BUILTIN_ENV_NAME = builtin_env
BUILTIN_ENV_PATH = src/lib/builtins/env
BUILTIN_ENV_FILE = ./libbuiltin_env.a
BUILTIN_ENV_SRCS = export.c print_exported_env.c set.c unset.c
BUILTIN_ENV_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(BUILTIN_ENV_SRCS))
BUILTIN_ENV_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(BUILTIN_ENV_SRCS))
BUILTIN_ENV_LIBS = 
BUILTIN_ENV_INCS = -I src/lib/builtins/src/lib/builtins/alias -I src/lib/builtins/cd -I src/lib/builtins/echo -I src/lib/builtins/env -I src/lib/libcc/optparse -I src/lib/liberror -I src/lib/libcc/hash_map -I src/lib/libcc/list -I src/lib/libenv -I src/lib/libcc/graph -I src/lib/libcc/string -I src/lib/libcc/num -I src/lib/libcc/sort -I src/lib/libcc/memory -I src/lib/libexpand

# **************************************************************************** #
# JOB_QUEUE TARGET DESCRIPTION

JOB_QUEUE_NAME = job_queue
JOB_QUEUE_PATH = src/lib/libjob/job_queue
JOB_QUEUE_FILE = ./libjob_queue.a
JOB_QUEUE_SRCS = queue_get_current.c queue_get_job_index_by_str.c queue_get_last.c queue_move_back.c queue_push_back.c queue_remove.c
JOB_QUEUE_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(JOB_QUEUE_SRCS))
JOB_QUEUE_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(JOB_QUEUE_SRCS))
JOB_QUEUE_LIBS = 
JOB_QUEUE_INCS = -I src/lib/libjob -I src/lib/liblex -I src/lib/libcc/vector -I src/lib/liberror -I src/lib/libparse -I src/lib/libcc/string

# **************************************************************************** #
# BUILTINS_HISTORY TARGET DESCRIPTION

BUILTINS_HISTORY_NAME = builtins_history
BUILTINS_HISTORY_PATH = src/lib/builtins/history
BUILTINS_HISTORY_FILE = ./libbuiltins_history.a
BUILTINS_HISTORY_SRCS = history.c
BUILTINS_HISTORY_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(BUILTINS_HISTORY_SRCS))
BUILTINS_HISTORY_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(BUILTINS_HISTORY_SRCS))
BUILTINS_HISTORY_LIBS = 
BUILTINS_HISTORY_INCS = -I src/lib/builtins/ -I src/lib/libhistory -I src/lib/libcc/vector

# **************************************************************************** #
# CC_STRING TARGET DESCRIPTION

CC_STRING_NAME = cc_string
CC_STRING_PATH = src/lib/libcc/string
CC_STRING_FILE = ./libcc_string.a
CC_STRING_SRCS = fdputendl.c fdputs.c itoa.c itoabase.c putendl.c puts.c strarr_del.c strarr_getsize.c strarr_print.c strcat.c strchr.c strclr.c strcmp.c strcpy.c strdel.c strdup.c strequ.c strhash.c strisnum.c strispath.c striter.c striteri.c strjoin.c strlcat.c strlen.c strmap.c strmapi.c strncat.c strncmp.c strncpy.c strnequ.c strnew.c strnjoin.c strnstr.c strrchr.c strsplit.c strsplitcharset.c strstr.c strsub.c strtrim.c utf8_display_strlen.c
CC_STRING_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(CC_STRING_SRCS))
CC_STRING_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(CC_STRING_SRCS))
CC_STRING_LIBS = 
CC_STRING_INCS = -I src/lib/libcc -I src/lib/libcc/string -I src/lib/libcc/char -I src/lib/libcc/memory -I src/lib/libcc/math

# **************************************************************************** #
# HASH TARGET DESCRIPTION

HASH_NAME = hash
HASH_PATH = src/lib/libhash
HASH_FILE = ./libhash.a
HASH_SRCS = hash_del.c hash_get_bin_path.c hash_get_path.c hash_init.c hash_insert.c hash_print.c
HASH_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(HASH_SRCS))
HASH_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(HASH_SRCS))
HASH_LIBS = 
HASH_INCS = -I src/lib/libhash -I src/lib/libcc/hash_map -I src/lib/libcc/list -I src/lib/libenv -I src/lib/libcc/graph -I src/lib/libcc/string -I src/lib/libcc/memory -I src/lib/libcc/num -I src/lib/libcc/char -I src/lib/liblex

# **************************************************************************** #
# 42SH TARGET DESCRIPTION

42SH_NAME = 42sh
42SH_PATH = src/bin/42sh
42SH_FILE = ./42sh
42SH_SRCS = main.c main_init.c main_manager.c
42SH_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(42SH_SRCS))
42SH_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(42SH_SRCS))
42SH_LIBS = -l ft_select -L . -l cc_optparse -L . -l builtin_cd -L . -l cc -L . -l parser -L . -l cc_regex -L . -l cc_file -L . -l jobs -L . -l cc_avl -L . -l cc_sort -L . -l builtin_echo -L . -l cc_list -L . -l cc_math -L . -l cc_char -L . -l env -L . -l cc_vector -L . -l calc -L . -l cc_num -L . -l builtin_env -L . -l job_queue -L . -l builtins_history -L . -l cc_string -L . -l hash -L . -l exec -L . -l job_builtins -L . -l lex -L . -l readline -L . -l expand -L . -l builtins_hash -L . -l cc_memory -L . -l alias -L . -l cc_hash_map -L . -l error -L . -l builtin_alias -L . -l history -L .
42SH_INCS = -I src/bin/42sh -I src/lib/libjob -I src/lib/liblex -I src/lib/libcc/vector -I src/lib/liberror -I src/lib/libparse -I src/lib/libenv -I src/lib/libcc/hash_map -I src/lib/libcc/list -I src/lib/libcc/graph -I src/lib/readline -I src/lib/libalias -I src/lib/libhistory -I src/lib/libcc/num -I src/lib/libcc/string -I src/lib/libhash -I src/lib/libexec

# **************************************************************************** #
# JOB_BUILTINS TARGET DESCRIPTION

JOB_BUILTINS_NAME = job_builtins
JOB_BUILTINS_PATH = src/lib/libjob/job_builtins
JOB_BUILTINS_FILE = ./libjob_builtins.a
JOB_BUILTINS_SRCS = bg_builtin.c bg_fg.c exit_builtin.c exit_shell.c fg_builtin.c jobs.c type.c
JOB_BUILTINS_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(JOB_BUILTINS_SRCS))
JOB_BUILTINS_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(JOB_BUILTINS_SRCS))
JOB_BUILTINS_LIBS = 
JOB_BUILTINS_INCS = -I src/lib/libjob -I src/lib/liblex -I src/lib/libcc/vector -I src/lib/liberror -I src/lib/libparse -I src/lib/libcc/char -I src/lib/libcc/num -I src/lib/libcc/string -I src/lib/libcc/hash_map -I src/lib/libcc/list -I src/lib/libenv -I src/lib/libcc/graph -I src/lib/libalias -I src/lib/libhistory -I src/lib/libcc/optparse -I src/lib/libhash

# **************************************************************************** #
# LEX TARGET DESCRIPTION

LEX_NAME = lex
LEX_PATH = src/lib/liblex
LEX_FILE = ./liblex.a
LEX_SRCS = destruct_token.c destruct_tokens.c exp_back_slash.c exp_dollar.c exp_double_quote.c exp_single_quote.c exp_unset.c expand_token.c get_brace.c get_current_state.c get_operator.c get_tokens.c is_delimiter.c is_doublequote_esc.c is_redirection.c lex_del.c lex_err.c lex_map.c lex_raw.c match_bang.c match_brace.c match_parameter.c match_tilda.c recognize_token.c replace_alias.c strjoin_expanded.c tok_bang.c tok_dollar.c tok_double_quote.c tok_single_quote.c tok_unset.c token_type_to_string.c validate_str.c vld_back_slash.c vld_bang.c vld_heredoc.c
LEX_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(LEX_SRCS))
LEX_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(LEX_SRCS))
LEX_LIBS = 
LEX_INCS = -I src/lib/liblex -I src/lib/libcc/vector -I src/lib/liberror -I src/lib/libcc/memory -I src/lib/libexpand -I src/lib/libcc/string -I src/lib/libcc/regex -I src/lib/libcc/num -I src/lib/libcc/char -I src/lib/libenv -I src/lib/libcc/hash_map -I src/lib/libcc/list -I src/lib/libcc/graph -I src/lib/libalias

# **************************************************************************** #
# READLINE TARGET DESCRIPTION

READLINE_NAME = readline
READLINE_PATH = src/lib/readline
READLINE_FILE = ./libreadline.a
READLINE_SRCS = check_for_utf8_comb_charecter.c clear_display_input.c clear_last_disp_token.c common_redraw.c del_inp_structure.c del_predict_token.c fill_complition_graph.c get_predict_token.c handle_etx.c handle_backspace.c handle_command_token.c handle_del.c handle_down_arrow.c handle_end_key.c handle_escape_sequense.c handle_file_token.c handle_home_key.c handle_key.c handle_left_arrow.c handle_param_token.c handle_right_arrow.c handle_shift_down.c handle_shift_left.c handle_shift_right.c handle_shift_up.c handle_symdol_key.c handle_tab.c handle_up_arrow.c input_init.c input_to_n_str.c input_to_str.c parse_filename.c print_propmt.c put_cursor_to_the_end.c put_str_to_input.c readline.c redraw_input.c redraw_input_redline.c reload_input.c select_choise.c split_newline.c try_to_print_same_part.c tty_init.c tty_restore.c
READLINE_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(READLINE_SRCS))
READLINE_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(READLINE_SRCS))
READLINE_LIBS = 
READLINE_INCS = -I src/lib/readline -I src/lib/libcc/vector -I src/lib/libcc/graph -I src/lib/libcc/list -I src/lib/liblex -I src/lib/liberror -I src/lib/libcc/string -I src/lib/libcc/char -I src/lib/libenv -I src/lib/libcc/hash_map -I src/lib/libcc -I src/lib/libcc/memory -I src/lib/ft_select -I src/lib/libhistory -I src/lib/libcc/num

# **************************************************************************** #
# EXPAND TARGET DESCRIPTION

EXPAND_NAME = expand
EXPAND_PATH = src/lib/libexpand
EXPAND_FILE = ./libexpand.a
EXPAND_SRCS = expand_bang.c expand_by_type.c expand_calc.c expand_exit_code.c expand_parameter.c expand_prefix.c expand_suffix.c expand_tilda.c get_env_or_av_value.c get_operator_type.c is_expand_err_code.c
EXPAND_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(EXPAND_SRCS))
EXPAND_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(EXPAND_SRCS))
EXPAND_LIBS = 
EXPAND_INCS = -I src/lib/libexpand -I src/lib/libcc/char -I src/lib/libcc/string -I src/lib/libcc/num -I src/lib/libhistory -I src/lib/libcc/vector -I src/lib/liberror -I src/lib/libenv -I src/lib/libcc/hash_map -I src/lib/libcc/list -I src/lib/libcc/graph -I src/lib/libcalc -I src/lib/libcc/regex

# **************************************************************************** #
# BUILTINS_HASH TARGET DESCRIPTION

BUILTINS_HASH_NAME = builtins_hash
BUILTINS_HASH_PATH = src/lib/builtins/hash
BUILTINS_HASH_FILE = ./libbuiltins_hash.a
BUILTINS_HASH_SRCS = hash.c
BUILTINS_HASH_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(BUILTINS_HASH_SRCS))
BUILTINS_HASH_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(BUILTINS_HASH_SRCS))
BUILTINS_HASH_LIBS = 
BUILTINS_HASH_INCS = -I src/lib/builtins -I src/lib/libhash -I src/lib/libcc/hash_map -I src/lib/libcc/list -I src/lib/libcc/optparse -I src/lib/liberror -I src/lib/libcc -I src/lib/libcc/string

# **************************************************************************** #
# CC_MEMORY TARGET DESCRIPTION

CC_MEMORY_NAME = cc_memory
CC_MEMORY_PATH = src/lib/libcc/memory
CC_MEMORY_FILE = ./libcc_memory.a
CC_MEMORY_SRCS = memalloc.c memccpy.c memchr.c memcmp.c memcpy.c memdel.c memmove.c memset.c xmalloc.c bzero.c
CC_MEMORY_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(CC_MEMORY_SRCS))
CC_MEMORY_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(CC_MEMORY_SRCS))
CC_MEMORY_LIBS = 
CC_MEMORY_INCS = -I src/lib/libcc -I src/lib/libcc/memory

# **************************************************************************** #
# ALIAS TARGET DESCRIPTION

ALIAS_NAME = alias
ALIAS_PATH = src/lib/libalias
ALIAS_FILE = ./libalias.a
ALIAS_SRCS = alias_add.c alias_cmp_pair.c alias_del.c alias_del_pair.c alias_get_value.c alias_init.c alias_print.c alias_remove.c
ALIAS_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(ALIAS_SRCS))
ALIAS_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(ALIAS_SRCS))
ALIAS_LIBS = 
ALIAS_INCS = -I src/lib/libalias -I src/lib/libcc/hash_map -I src/lib/libcc/list -I src/lib/libcc/string -I src/lib/libcc/char -I src/lib/libcc/memory -I src/lib/libcc/sort

# **************************************************************************** #
# CC_HASH_MAP TARGET DESCRIPTION

CC_HASH_MAP_NAME = cc_hash_map
CC_HASH_MAP_PATH = src/lib/libcc/hash_map
CC_HASH_MAP_FILE = ./libcc_hash_map.a
CC_HASH_MAP_SRCS = hash_map_del.c hash_map_del_one.c hash_map_get_pair.c hash_map_get_size.c hash_map_get_val.c hash_map_insert.c hash_map_iter.c hash_map_new.c
CC_HASH_MAP_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(CC_HASH_MAP_SRCS))
CC_HASH_MAP_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(CC_HASH_MAP_SRCS))
CC_HASH_MAP_LIBS = 
CC_HASH_MAP_INCS = -I src/lib/libcc -I src/lib/libcc/hash_map -I src/lib/libcc/list -I src/lib/libcc/memory

# **************************************************************************** #
# ERROR TARGET DESCRIPTION

ERROR_NAME = error
ERROR_PATH = src/lib/liberror
ERROR_FILE = ./liberror.a
ERROR_SRCS = error_print.c print_invalid_option.c
ERROR_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(ERROR_SRCS))
ERROR_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(ERROR_SRCS))
ERROR_LIBS = 
ERROR_INCS = -I src/lib/liberror -I src/lib/libcc/char -I src/lib/libcc/string

# **************************************************************************** #
# BUILTIN_ALIAS TARGET DESCRIPTION

BUILTIN_ALIAS_NAME = builtin_alias
BUILTIN_ALIAS_PATH = src/lib/builtins/alias
BUILTIN_ALIAS_FILE = ./libbuiltin_alias.a
BUILTIN_ALIAS_SRCS = alias.c alias_bash_error_print.c alias_check_opt.c alias_usage_error_print.c unalias.c
BUILTIN_ALIAS_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(BUILTIN_ALIAS_SRCS))
BUILTIN_ALIAS_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(BUILTIN_ALIAS_SRCS))
BUILTIN_ALIAS_LIBS = 
BUILTIN_ALIAS_INCS = -I src/lib/builtins/ -I src/lib/builtins/alias -I src/lib/libalias -I src/lib/libcc/hash_map -I src/lib/libcc/list -I src/lib/liberror -I src/lib/libcc -I src/lib/libcc/optparse -I src/lib/libcc/string

# **************************************************************************** #
# HISTORY TARGET DESCRIPTION

HISTORY_NAME = history
HISTORY_PATH = src/lib/libhistory
HISTORY_FILE = ./libhistory.a
HISTORY_SRCS = hist_get_by_index.c hist_get_by_prefix.c hist_get_last.c hist_get_next.c hist_get_prev.c hist_init.c hist_print.c hist_push.c hist_reset_cur_ind.c hist_save.c
HISTORY_OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(HISTORY_SRCS))
HISTORY_DEPS = $(patsubst %, $(OBJ_DIR)/%.d, $(HISTORY_SRCS))
HISTORY_LIBS = 
HISTORY_INCS = -I src/lib/libhistory -I src/lib/libcc/vector -I src/lib/libcc -I src/lib/libcc/list -I src/lib/libcc/string -I src/lib/libcc/file

# **************************************************************************** #
# GENERIC RULES

.PHONY: all re clean fclean
.DEFAULT_GOAL = all

all: $(FT_SELECT_FILE) $(CC_OPTPARSE_FILE) $(BUILTIN_CD_FILE) $(CC_FILE) $(PARSER_FILE) $(CC_REGEX_FILE) $(CC_FILE_FILE) $(JOBS_FILE) $(CC_AVL_FILE) $(CC_SORT_FILE) $(EXEC_FILE) $(BUILTIN_ECHO_FILE) $(CC_LIST_FILE) $(CC_MATH_FILE) $(CC_CHAR_FILE) $(ENV_FILE) $(CC_VECTOR_FILE) $(CALC_FILE) $(CC_NUM_FILE) $(BUILTIN_ENV_FILE) $(JOB_QUEUE_FILE) $(BUILTINS_HISTORY_FILE) $(CC_STRING_FILE) $(HASH_FILE) $(JOB_BUILTINS_FILE) $(LEX_FILE) $(READLINE_FILE) $(EXPAND_FILE) $(BUILTINS_HASH_FILE) $(CC_MEMORY_FILE) $(ALIAS_FILE) $(CC_HASH_MAP_FILE) $(ERROR_FILE) $(BUILTIN_ALIAS_FILE) $(HISTORY_FILE) $(42SH_FILE)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(FT_SELECT_FILE) $(CC_OPTPARSE_FILE) $(BUILTIN_CD_FILE) $(CC_FILE) $(PARSER_FILE) $(CC_REGEX_FILE) $(CC_FILE_FILE) $(JOBS_FILE) $(CC_AVL_FILE) $(CC_SORT_FILE) $(EXEC_FILE) $(BUILTIN_ECHO_FILE) $(CC_LIST_FILE) $(CC_MATH_FILE) $(CC_CHAR_FILE) $(ENV_FILE) $(CC_VECTOR_FILE) $(CALC_FILE) $(CC_NUM_FILE) $(BUILTIN_ENV_FILE) $(JOB_QUEUE_FILE) $(BUILTINS_HISTORY_FILE) $(CC_STRING_FILE) $(HASH_FILE) $(JOB_BUILTINS_FILE) $(LEX_FILE) $(READLINE_FILE) $(EXPAND_FILE) $(BUILTINS_HASH_FILE) $(CC_MEMORY_FILE) $(ALIAS_FILE) $(CC_HASH_MAP_FILE) $(ERROR_FILE) $(BUILTIN_ALIAS_FILE) $(HISTORY_FILE) $(42SH_FILE)

re: fclean all

$(FT_SELECT_FILE): $(FT_SELECT_OBJS)
	@ar rc $(FT_SELECT_FILE) $(FT_SELECT_OBJS)
	@ranlib $(FT_SELECT_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(FT_SELECT_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(FT_SELECT_INCS) -o $@ -c $< -MMD

$(CC_OPTPARSE_FILE): $(CC_OPTPARSE_OBJS)
	@ar rc $(CC_OPTPARSE_FILE) $(CC_OPTPARSE_OBJS)
	@ranlib $(CC_OPTPARSE_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(CC_OPTPARSE_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(CC_OPTPARSE_INCS) -o $@ -c $< -MMD

$(BUILTIN_CD_FILE): $(BUILTIN_CD_OBJS)
	@ar rc $(BUILTIN_CD_FILE) $(BUILTIN_CD_OBJS)
	@ranlib $(BUILTIN_CD_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(BUILTIN_CD_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(BUILTIN_CD_INCS) -o $@ -c $< -MMD

$(CC_FILE): $(CC_OBJS)
	@ar rc $(CC_FILE) $(CC_OBJS)
	@ranlib $(CC_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(CC_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(CC_INCS) -o $@ -c $< -MMD

$(PARSER_FILE): $(PARSER_OBJS)
	@ar rc $(PARSER_FILE) $(PARSER_OBJS)
	@ranlib $(PARSER_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(PARSER_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(PARSER_INCS) -o $@ -c $< -MMD

$(CC_REGEX_FILE): $(CC_REGEX_OBJS)
	@ar rc $(CC_REGEX_FILE) $(CC_REGEX_OBJS)
	@ranlib $(CC_REGEX_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(CC_REGEX_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(CC_REGEX_INCS) -o $@ -c $< -MMD

$(CC_FILE_FILE): $(CC_FILE_OBJS)
	@ar rc $(CC_FILE_FILE) $(CC_FILE_OBJS)
	@ranlib $(CC_FILE_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(CC_FILE_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(CC_FILE_INCS) -o $@ -c $< -MMD

$(JOBS_FILE): $(JOBS_OBJS)
	@ar rc $(JOBS_FILE) $(JOBS_OBJS)
	@ranlib $(JOBS_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(JOBS_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(JOBS_INCS) -o $@ -c $< -MMD

$(CC_AVL_FILE): $(CC_AVL_OBJS)
	@ar rc $(CC_AVL_FILE) $(CC_AVL_OBJS)
	@ranlib $(CC_AVL_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(CC_AVL_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(CC_AVL_INCS) -o $@ -c $< -MMD

$(CC_SORT_FILE): $(CC_SORT_OBJS)
	@ar rc $(CC_SORT_FILE) $(CC_SORT_OBJS)
	@ranlib $(CC_SORT_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(CC_SORT_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(CC_SORT_INCS) -o $@ -c $< -MMD

$(EXEC_FILE): $(EXEC_OBJS)
	@ar rc $(EXEC_FILE) $(EXEC_OBJS)
	@ranlib $(EXEC_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(EXEC_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(EXEC_INCS) -o $@ -c $< -MMD

$(BUILTIN_ECHO_FILE): $(BUILTIN_ECHO_OBJS)
	@ar rc $(BUILTIN_ECHO_FILE) $(BUILTIN_ECHO_OBJS)
	@ranlib $(BUILTIN_ECHO_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(BUILTIN_ECHO_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(BUILTIN_ECHO_INCS) -o $@ -c $< -MMD

$(CC_LIST_FILE): $(CC_LIST_OBJS)
	@ar rc $(CC_LIST_FILE) $(CC_LIST_OBJS)
	@ranlib $(CC_LIST_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(CC_LIST_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(CC_LIST_INCS) -o $@ -c $< -MMD

$(CC_MATH_FILE): $(CC_MATH_OBJS)
	@ar rc $(CC_MATH_FILE) $(CC_MATH_OBJS)
	@ranlib $(CC_MATH_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(CC_MATH_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(CC_MATH_INCS) -o $@ -c $< -MMD

$(CC_CHAR_FILE): $(CC_CHAR_OBJS)
	@ar rc $(CC_CHAR_FILE) $(CC_CHAR_OBJS)
	@ranlib $(CC_CHAR_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(CC_CHAR_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(CC_CHAR_INCS) -o $@ -c $< -MMD

$(ENV_FILE): $(ENV_OBJS)
	@ar rc $(ENV_FILE) $(ENV_OBJS)
	@ranlib $(ENV_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(ENV_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(ENV_INCS) -o $@ -c $< -MMD

$(CC_VECTOR_FILE): $(CC_VECTOR_OBJS)
	@ar rc $(CC_VECTOR_FILE) $(CC_VECTOR_OBJS)
	@ranlib $(CC_VECTOR_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(CC_VECTOR_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(CC_VECTOR_INCS) -o $@ -c $< -MMD

$(CALC_FILE): $(CALC_OBJS)
	@ar rc $(CALC_FILE) $(CALC_OBJS)
	@ranlib $(CALC_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(CALC_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(CALC_INCS) -o $@ -c $< -MMD

$(CC_NUM_FILE): $(CC_NUM_OBJS)
	@ar rc $(CC_NUM_FILE) $(CC_NUM_OBJS)
	@ranlib $(CC_NUM_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(CC_NUM_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(CC_NUM_INCS) -o $@ -c $< -MMD

$(BUILTIN_ENV_FILE): $(BUILTIN_ENV_OBJS)
	@ar rc $(BUILTIN_ENV_FILE) $(BUILTIN_ENV_OBJS)
	@ranlib $(BUILTIN_ENV_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(BUILTIN_ENV_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(BUILTIN_ENV_INCS) -o $@ -c $< -MMD

$(JOB_QUEUE_FILE): $(JOB_QUEUE_OBJS)
	@ar rc $(JOB_QUEUE_FILE) $(JOB_QUEUE_OBJS)
	@ranlib $(JOB_QUEUE_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(JOB_QUEUE_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(JOB_QUEUE_INCS) -o $@ -c $< -MMD

$(BUILTINS_HISTORY_FILE): $(BUILTINS_HISTORY_OBJS)
	@ar rc $(BUILTINS_HISTORY_FILE) $(BUILTINS_HISTORY_OBJS)
	@ranlib $(BUILTINS_HISTORY_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(BUILTINS_HISTORY_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(BUILTINS_HISTORY_INCS) -o $@ -c $< -MMD

$(CC_STRING_FILE): $(CC_STRING_OBJS)
	@ar rc $(CC_STRING_FILE) $(CC_STRING_OBJS)
	@ranlib $(CC_STRING_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(CC_STRING_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(CC_STRING_INCS) -o $@ -c $< -MMD

$(HASH_FILE): $(HASH_OBJS)
	@ar rc $(HASH_FILE) $(HASH_OBJS)
	@ranlib $(HASH_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(HASH_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(HASH_INCS) -o $@ -c $< -MMD

$(42SH_FILE): $(FT_SELECT_FILE) $(CC_OPTPARSE_FILE) $(BUILTIN_CD_FILE) $(CC_FILE) $(PARSER_FILE) $(CC_REGEX_FILE) $(CC_FILE_FILE) $(JOBS_FILE) $(CC_AVL_FILE) $(CC_SORT_FILE) $(BUILTIN_ECHO_FILE) $(CC_LIST_FILE) $(CC_MATH_FILE) $(CC_CHAR_FILE) $(ENV_FILE) $(CC_VECTOR_FILE) $(CALC_FILE) $(CC_NUM_FILE) $(BUILTIN_ENV_FILE) $(JOB_QUEUE_FILE) $(BUILTINS_HISTORY_FILE) $(CC_STRING_FILE) $(HASH_FILE) $(EXEC_FILE) $(JOB_BUILTINS_FILE) $(LEX_FILE) $(READLINE_FILE) $(EXPAND_FILE) $(BUILTINS_HASH_FILE) $(CC_MEMORY_FILE) $(ALIAS_FILE) $(CC_HASH_MAP_FILE) $(ERROR_FILE) $(BUILTIN_ALIAS_FILE) $(HISTORY_FILE) $(42SH_OBJS)
	@$(C_COMPILER) $(C_LFLAGS) $(C_STANDART) -ltermcap -o $(42SH_FILE) $(42SH_OBJS)  $(42SH_LIBS)
	@printf 'Finished	\033[1;32m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(42SH_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(42SH_INCS) -o $@ -c $< -MMD

$(JOB_BUILTINS_FILE): $(JOB_BUILTINS_OBJS)
	@ar rc $(JOB_BUILTINS_FILE) $(JOB_BUILTINS_OBJS)
	@ranlib $(JOB_BUILTINS_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(JOB_BUILTINS_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(JOB_BUILTINS_INCS) -o $@ -c $< -MMD

$(LEX_FILE): $(LEX_OBJS)
	@ar rc $(LEX_FILE) $(LEX_OBJS)
	@ranlib $(LEX_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(LEX_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(LEX_INCS) -o $@ -c $< -MMD

$(READLINE_FILE): $(READLINE_OBJS)
	@ar rc $(READLINE_FILE) $(READLINE_OBJS)
	@ranlib $(READLINE_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(READLINE_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(READLINE_INCS) -o $@ -c $< -MMD

$(EXPAND_FILE): $(EXPAND_OBJS)
	@ar rc $(EXPAND_FILE) $(EXPAND_OBJS)
	@ranlib $(EXPAND_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(EXPAND_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(EXPAND_INCS) -o $@ -c $< -MMD

$(BUILTINS_HASH_FILE): $(BUILTINS_HASH_OBJS)
	@ar rc $(BUILTINS_HASH_FILE) $(BUILTINS_HASH_OBJS)
	@ranlib $(BUILTINS_HASH_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(BUILTINS_HASH_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(BUILTINS_HASH_INCS) -o $@ -c $< -MMD

$(CC_MEMORY_FILE): $(CC_MEMORY_OBJS)
	@ar rc $(CC_MEMORY_FILE) $(CC_MEMORY_OBJS)
	@ranlib $(CC_MEMORY_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(CC_MEMORY_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(CC_MEMORY_INCS) -o $@ -c $< -MMD

$(ALIAS_FILE): $(ALIAS_OBJS)
	@ar rc $(ALIAS_FILE) $(ALIAS_OBJS)
	@ranlib $(ALIAS_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(ALIAS_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(ALIAS_INCS) -o $@ -c $< -MMD

$(CC_HASH_MAP_FILE): $(CC_HASH_MAP_OBJS)
	@ar rc $(CC_HASH_MAP_FILE) $(CC_HASH_MAP_OBJS)
	@ranlib $(CC_HASH_MAP_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(CC_HASH_MAP_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(CC_HASH_MAP_INCS) -o $@ -c $< -MMD

$(ERROR_FILE): $(ERROR_OBJS)
	@ar rc $(ERROR_FILE) $(ERROR_OBJS)
	@ranlib $(ERROR_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(ERROR_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(ERROR_INCS) -o $@ -c $< -MMD

$(BUILTIN_ALIAS_FILE): $(BUILTIN_ALIAS_OBJS)
	@ar rc $(BUILTIN_ALIAS_FILE) $(BUILTIN_ALIAS_OBJS)
	@ranlib $(BUILTIN_ALIAS_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(BUILTIN_ALIAS_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(BUILTIN_ALIAS_INCS) -o $@ -c $< -MMD

$(HISTORY_FILE): $(HISTORY_OBJS)
	@ar rc $(HISTORY_FILE) $(HISTORY_OBJS)
	@ranlib $(HISTORY_FILE)
	@printf 'Finished	\033[1;36m\033[7m$@ \033[0m\n\n'

$(OBJ_DIR)/%.c.o: $(HISTORY_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	@printf 'Compiling	\033[1;33m$<\033[0m ...\n'
	@$(C_COMPILER) $(C_CFLAGS) $(C_STANDART) $(HISTORY_INCS) -o $@ -c $< -MMD

-include $(FT_SELECT_DEPS) $(CC_OPTPARSE_DEPS) $(BUILTIN_CD_DEPS) $(CC_DEPS) $(PARSER_DEPS) $(CC_REGEX_DEPS) $(CC_FILE_DEPS) $(JOBS_DEPS) $(CC_AVL_DEPS) $(CC_SORT_DEPS) $(EXEC_DEPS) $(BUILTIN_ECHO_DEPS) $(CC_LIST_DEPS) $(CC_MATH_DEPS) $(CC_CHAR_DEPS) $(ENV_DEPS) $(CC_VECTOR_DEPS) $(CALC_DEPS) $(CC_NUM_DEPS) $(BUILTIN_ENV_DEPS) $(JOB_QUEUE_DEPS) $(BUILTINS_HISTORY_DEPS) $(CC_STRING_DEPS) $(HASH_DEPS) $(42SH_DEPS) $(JOB_BUILTINS_DEPS) $(LEX_DEPS) $(READLINE_DEPS) $(EXPAND_DEPS) $(BUILTINS_HASH_DEPS) $(CC_MEMORY_DEPS) $(ALIAS_DEPS) $(CC_HASH_MAP_DEPS) $(ERROR_DEPS) $(BUILTIN_ALIAS_DEPS) $(HISTORY_DEPS)
