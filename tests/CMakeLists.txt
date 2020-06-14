cmake_minimum_required(VERSION 3.8)
project(42sh_tests C)

set(CMAKE_C_STANDARD 99)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror")
set(GCC_COVERAGE_LINK_FLAGS    "-Wall -Wextra -Werror")



add_executable(${PROJECT_NAME} tests.c)

#add libcc to the project
target_link_libraries(${PROJECT_NAME} cc)

#add liblists to the project
target_link_libraries(${PROJECT_NAME} lists)


#add libtestutils to the project
target_link_libraries(${PROJECT_NAME} testutils)

#add libhistory to the project
target_link_libraries(${PROJECT_NAME} history)

#add liblex to the project
target_link_libraries(${PROJECT_NAME} lex)


include_directories (
    ../src/lib/libcc
    ../src/lib/libhistory
    ../src/lib/liblex
    ../src/lib/liblists
                     )

#add libtestutils to the project
set(LIBTU_DIR "libtestutils")
include_directories(${LIBTU_DIR})
add_subdirectory(${LIBTU_DIR})
target_link_libraries(${PROJECT_NAME} testutils)


#add libhistory_tests to the project
set(LIBHT_DIR "libhistory_tests")
include_directories(${LIBHT_DIR})
add_subdirectory(${LIBHT_DIR})
target_link_libraries(${PROJECT_NAME} history_tests)


#add liblex_tests to the project
set(LIBLT_DIR "liblex_tests")
include_directories(${LIBLT_DIR})
add_subdirectory(${LIBLT_DIR})
target_link_libraries(${PROJECT_NAME} lex_tests)

