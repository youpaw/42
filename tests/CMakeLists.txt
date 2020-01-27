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

#add libhistory to the project
target_link_libraries(${PROJECT_NAME} history)


include_directories (
    ../src/lib/libcc
    ../src/lib/libhistory
    ../src/lib/liblists
                     )

  message(STATUS "{{CMAKE_CURRENT_SOURCE_DIR}}='${CMAKE_CURRENT_SOURCE_DIR}'")



get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${dirs})
  message(STATUS "dir='${dir}'")
endforeach()


#add libhistory_tests to the project
set(LIBHT_DIR "libhistory_tests")
include_directories(${LIBHT_DIR})
add_subdirectory(${LIBHT_DIR})
target_link_libraries(${PROJECT_NAME} history_tests)

