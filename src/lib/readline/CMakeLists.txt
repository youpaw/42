cmake_minimum_required(VERSION 3.8)

# CMake instructions to compile readline as static lib

set(READLINE_BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${READLINE_BUILD_DIRECTORY})

#set(LIBRARY_OUTPUT_PATH "build")
#set(CMAKE_CACHEFILE_DIR ${LIBCC_BUILD_DIRECTORY})

ADD_LIBRARY(readline STATIC
        readline.c
        termcap_init.c output.c input.c arrows_handle.c del_charecters.c symbol_handle.c tmp_fncts.c autocomplite.c tty_init.c tty_restore.c input_to_str.c)

target_link_libraries(readline cc termcap)

