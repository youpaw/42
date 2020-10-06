cmake_minimum_required(VERSION 3.8)

# CMake instructions to compile libcc as static lib

set(BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${BUILD_DIRECTORY})


ADD_LIBRARY(jobs STATIC
            print_process_stats.c
        print_jobs.c jobs_init.c add_job_to_list.c signal_handlers.c is_root_process.c remove_job_by_index.c check_jobs.c remove_job_by_pid.c)

        
target_link_libraries(jobs cc)
