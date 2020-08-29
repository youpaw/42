cmake_minimum_required(VERSION 3.8)

# CMake instructions to compile libenv as static lib

set(LIBENV_BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${LIBENV_BUILD_DIRECTORY})

#set(LIBRARY_OUTPUT_PATH "build")
#set(CMAKE_CACHEFILE_DIR ${LIBCC_BUILD_DIRECTORY})

ADD_LIBRARY(env STATIC
        get_valid_name_length.c exec_env_insert.c exec_env_init.c exec_env_2array.c env_init.c av_init.c env_del.c av_get.c env_print_global.c env_del_pair.c env_insert_to.c env_remove_from.c env_print_full.c env_cmp_pair.c env_get_value.c exec_env_del.c env_print_pair.c arr2_quick_sort.c arr2.c av_del.c)

target_link_libraries(env cc)