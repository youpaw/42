cmake_minimum_required(VERSION 3.8)

# CMake instructions to compile lib as static lib

set(BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${BUILD_DIRECTORY})


ADD_LIBRARY(lists STATIC
    lstadd.c
    lstdel.c
    lstdelone.c
    lst_count.c
    lst_find.c
    lst_free.c
    lst_free_item.c
    lst_get_last.c
    lst_insert.c
    lstiter.c
    lstmap.c
    lstnew.c
    lst_reduce.c
    lst_remove_sorted.c
    lst_save.c
    lst_load.c
    )

        
target_link_libraries(lists cc)