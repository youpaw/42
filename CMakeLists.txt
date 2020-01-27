cmake_minimum_required(VERSION 3.8)
project(42sh C)

set(CMAKE_C_STANDARD 99)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror")
set(GCC_COVERAGE_LINK_FLAGS    "-Wall -Wextra -Werror")


add_subdirectory(src)

enable_testing()
add_subdirectory(tests)

