cmake_minimum_required(VERSION 3.8)
project(42sh C)

set(CMAKE_C_STANDARD 99)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror")
set(GCC_COVERAGE_LINK_FLAGS    "-Wall -Wextra -Werror")

add_executable(${PROJECT_NAME} bin/42sh/main.c)

#add libhistory to the project
set(LIBH_DIR "lib/libhistory")
include_directories(${LIBH_DIR})
add_subdirectory(${LIBH_DIR})
target_link_libraries(${PROJECT_NAME} history)

#add libcc to the project
set(LIBCC_DIR "lib/libcc")
include_directories(${LIBCC_DIR})
add_subdirectory(${LIBCC_DIR})
target_link_libraries(${PROJECT_NAME} cc)

#add libenv to the project
set(LIBENV_DIR "lib/libenv")
include_directories(${LIBENV_DIR})
add_subdirectory(${LIBENV_DIR})
target_link_libraries(${PROJECT_NAME} env)

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

#add readline to the project
set(READLINE_DIR "lib/readline")
include_directories(${READLINE_DIR})
add_subdirectory(${READLINE_DIR})
target_link_libraries(${PROJECT_NAME} readline)

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
