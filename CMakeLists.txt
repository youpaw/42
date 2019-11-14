cmake_minimum_required(VERSION 3.8)
project(42sh C)

set(CMAKE_C_STANDARD 99)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror")
set(GCC_COVERAGE_LINK_FLAGS    "-Wall -Wextra -Werror")

add_executable(${PROJECT_NAME} src/bin/42sh/main.c)

#target_include_directories(${PROJECT_NAME} PRIVATE "src/lib/libcc")
include_directories("src/lib/libcc")
add_subdirectory("src/lib/libcc")

#target_include_directories("src/lib/libcc")
target_link_libraries(${PROJECT_NAME} cc)