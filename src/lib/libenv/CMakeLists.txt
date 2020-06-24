cmake_minimum_required(VERSION 3.8)

# CMake instructions to compile libenv as static lib

set(LIBENV_BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${LIBENV_BUILD_DIRECTORY})

#set(LIBRARY_OUTPUT_PATH "build")
#set(CMAKE_CACHEFILE_DIR ${LIBCC_BUILD_DIRECTORY})

ADD_LIBRARY(env STATIC
        get_name_length.c env_init.c env_add_field.c av_init.c env_del.c env_get_field.c env_get_field_val.c av_set.c av_get.c exec_env_init.c exec_env_add.c print_env.c print_all.c env_del_pair.c)

target_link_libraries(env cc)