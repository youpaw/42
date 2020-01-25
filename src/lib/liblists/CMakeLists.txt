cmake_minimum_required(VERSION 3.8)

# CMake instructions to compile lib as static lib

set(BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${BUILD_DIRECTORY})


ADD_LIBRARY(lists STATIC
    lst_count.c
    lst_find.c
    lst_free.c
    lst_free_item.c
    lst_insert.c
    lst_reduce.c
    lst_remove_sorted.c
    lstadd.c
    lstdel.c
    lstdelone.c
    lstiter.c
    lstmap.c
    lstnew.c
    )

        
target_link_libraries(lists cc)