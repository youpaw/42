cmake_minimum_required(VERSION 3.8)

# CMake instructions to compile lib as static lib

set(BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${BUILD_DIRECTORY})



ADD_LIBRARY(lex_tests STATIC
        tests.c
        utils.c)

        
target_link_libraries(lex_tests cc)
target_link_libraries(lex_tests lex)
target_link_libraries(lex_tests testutils)