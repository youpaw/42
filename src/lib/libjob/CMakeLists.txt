cmake_minimum_required(VERSION 3.8)

# CMake instructions to compile libcc as static lib

set(BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${BUILD_DIRECTORY})


ADD_LIBRARY(jobs STATIC
            print_process_stats.c
        print_jobs.c jobs_init.c jobs_add.c signal_handlers.c)

        
target_link_libraries(jobs cc)
