cmake_minimum_required(VERSION 3.8)
project(42sh C)

set(CMAKE_C_STANDARD 99)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror")
set(GCC_COVERAGE_LINK_FLAGS    "-Wall -Wextra -Werror")

add_executable(${PROJECT_NAME} bin/42sh/main.c bin/42sh/ft_select.h bin/42sh/main_init.c bin/42sh/main_manager.c bin/42sh/main.c)

#add libcc to the project
set(LIBCC_DIR "lib/libcc")
include_directories(${LIBCC_DIR})
add_subdirectory(${LIBCC_DIR})
target_link_libraries(${PROJECT_NAME} cc)

#add liberror to the project
set(LIBERROR_DIR "lib/liberror")
include_directories(${LIBERROR_DIR})
add_subdirectory(${LIBERROR_DIR})
target_link_libraries(${PROJECT_NAME} error)

#add libcalc to the project
set(LIBCALC_DIR "lib/libcalc")
include_directories(${LIBCALC_DIR})
add_subdirectory(${LIBCALC_DIR})
target_link_libraries(${PROJECT_NAME} calc)

#add libalias to the project
set(LIBALIAS_DIR "lib/libalias")
include_directories(${LIBALIAS_DIR})
add_subdirectory(${LIBALIAS_DIR})
target_link_libraries(${PROJECT_NAME} alias)

#add libenv to the project
set(LIBENV_DIR "lib/libenv")
include_directories(${LIBENV_DIR})
add_subdirectory(${LIBENV_DIR})
target_link_libraries(${PROJECT_NAME} env)

#add libhistory to the project
set(LIBH_DIR "lib/libhistory")
include_directories(${LIBH_DIR})
add_subdirectory(${LIBH_DIR})
target_link_libraries(${PROJECT_NAME} history)

#add libhash to the project
set(LIBHASH_DIR "lib/libhash")
include_directories(${LIBHASH_DIR})
add_subdirectory(${LIBHASH_DIR})
target_link_libraries(${PROJECT_NAME} hash)

#add libexpand to the project
set(LIBEXPAND_DIR "lib/libexpand")
include_directories(${LIBEXPAND_DIR})
add_subdirectory(${LIBEXPAND_DIR})
target_link_libraries(${PROJECT_NAME} expand)

#add liblex to the project
set(LIBLEX_DIR "lib/liblex")
include_directories(${LIBLEX_DIR})
add_subdirectory(${LIBLEX_DIR})
target_link_libraries(${PROJECT_NAME} lex)

#add ft_select to the project
set(FT_SELECT_DIR "lib/ft_select")
include_directories(${FT_SELECT_DIR})
add_subdirectory(${FT_SELECT_DIR})
target_link_libraries(${PROJECT_NAME} ft_select)

#add readline to the project
set(READLINE_DIR "lib/readline")
include_directories(${READLINE_DIR})
add_subdirectory(${READLINE_DIR})
target_link_libraries(${PROJECT_NAME} readline)

#add libparse to the project
set(LIBPARSE_DIR "lib/libparse")
include_directories(${LIBPARSE_DIR})
add_subdirectory(${LIBPARSE_DIR})
target_link_libraries(${PROJECT_NAME} parser)

#add builtins to the project
set(BUILTINS_DIR "lib/builtins")
include_directories(${BUILTINS_DIR})
add_subdirectory(${BUILTINS_DIR})
target_link_libraries(${PROJECT_NAME} builtins)

#add libexec to the project
set(LIBEXEC_DIR "lib/libexec")
include_directories(${LIBEXEC_DIR})
add_subdirectory(${LIBEXEC_DIR})
target_link_libraries(${PROJECT_NAME} exec)