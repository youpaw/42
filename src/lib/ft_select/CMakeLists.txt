cmake_minimum_required(VERSION 3.8)

# CMake instructions to compile readline as static lib

set(READLINE_BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${READLINE_BUILD_DIRECTORY})

#set(LIBRARY_OUTPUT_PATH "build")
#set(CMAKE_CACHEFILE_DIR ${LIBCC_BUILD_DIRECTORY})

ADD_LIBRARY(ft_select STATIC
        ft_select.c
        cursor.c                cursor_more.c           draw.c ft_select.c ft_select.h init_and_signals.c      select_args.c           support_1.c get_winsize.c support_3.c             termcap_extra.c         two_side_list.c)

        target_link_libraries(ft_select cc termcap)

