cmake_minimum_required(VERSION 3.8)

# CMake instructions to compile libcc as static lib

set(BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${BUILD_DIRECTORY})


ADD_LIBRARY(jobs STATIC
        jobs_init.c put_job_in_foreground.c put_job_in_background.c mark_process_status.c update_status.c wait_for_job.c do_job_notification.c mark_job_as_running.c continue_job.c signal_handlers.c job_new.c process_new.c launch_job.c launch_process.c job_is_stopped.c job_is_completed.c push_job.c free_processes.c
        job_builtins/exit_builtin.c job_builtins/jobs.c job_builtins/fg_builtin.c job_builtins/bg_builtin.c job_queue/queue_move_back.c job_queue/queue_push_back.c job_queue/queue_remove.c job_queue/queue_get_current.c job_queue/queue_get_last.c get_new_job_index.c find_job_by_index.c remove_job.c print_job_formatted.c
        wait_for_job_complete.c job_builtins/bg_fg.c get_last_process_status.c free_all_jobs.c feee_job.c get_status_message.c job_builtins/exit_shell.c fork_and_launch_processes.c run_builtin_or_hash.c get_builtin_index.c exec_builtin_by_index.c is_standard_io.c process_init.c set_redirects.c job_queue/queue_get_job_index_by_str.c print_job_status_str.c get_status_sign_for_job.c print_job_pid.c redirect_less_and_right_side.c job_builtins/type.c)

        
target_link_libraries(jobs cc lex builtins parser)
