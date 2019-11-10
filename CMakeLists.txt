cmake_minimum_required(VERSION 3.15)
project(42 C)

set(CMAKE_C_STANDARD 99)

SET(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror")
SET(GCC_COVERAGE_LINK_FLAGS    "-Wall -Wextra -Werror")

add_executable(42 main.c)