cmake_minimum_required(VERSION 3.8)
project(42sh C)

set(CMAKE_C_STANDARD 99)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror")
set(GCC_COVERAGE_LINK_FLAGS    "-Wall -Wextra -Werror")

add_executable(${PROJECT_NAME} bin/42sh/main.c)

#add libcc to the project
set(LIBCC_DIR "lib/libcc")
include_directories(${LIBCC_DIR})
add_subdirectory(${LIBCC_DIR})
target_link_libraries(${PROJECT_NAME} cc)

#add liblists to the project
set(LIBLISTS_DIR "lib/liblists")
include_directories(${LIBLISTS_DIR})
add_subdirectory(${LIBLISTS_DIR})
target_link_libraries(${PROJECT_NAME} lists)

#add libhistory to the project
set(LIBH_DIR "lib/libhistory")
include_directories(${LIBH_DIR})
add_subdirectory(${LIBH_DIR})
target_link_libraries(${PROJECT_NAME} history)

#add libexec to the project
set(LIBEXEC_DIR "lib/libexec")
include_directories(${LIBEXEC_DIR})
add_subdirectory(${LIBEXEC_DIR})
target_link_libraries(${PROJECT_NAME} exec)

#add libhistory_tests to the project
#set(LIBHT_DIR "lib/libhistory_tests")
#include_directories(${LIBHT_DIR})
#add_subdirectory(${LIBHT_DIR})
#target_link_libraries(${PROJECT_NAME} history_tests)

