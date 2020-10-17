cmake_minimum_required(VERSION 3.8)

# CMake instructions to compile libcc as static lib

set(BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${BUILD_DIRECTORY})


ADD_LIBRARY(jobs STATIC
            print_process_stats.c
        jobs_init.c put_job_in_foreground.c put_job_in_background.c mark_process_status.c update_status.c wait_for_job.c format_job_info.c do_job_notification.c mark_job_as_running.c continue_job.c signal_handlers.c job_new.c process_new.c launch_job.c launch_process.c find_job.c job_is_stopped.c job_is_completed.c push_job.c del_job_by_pid.c del_process.c job_builtins.c)

        
target_link_libraries(jobs cc lex builtins)
