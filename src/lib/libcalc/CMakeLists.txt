cmake_minimum_required(VERSION 3.8)

set(LIBCALC_BUILD_DIRECTORY "build")
file(MAKE_DIRECTORY ${LIBCALC_BUILD_DIRECTORY})
#set(LIBRARY_OUTPUT_PATH "build")
#set(CMAKE_CACHEFILE_DIR ${LIBCC_BUILD_DIRECTORY})

ADD_LIBRARY(calc STATIC
        calc.c
        calc_tokenize.c
        calc_is_forbidden.c calc_get_token.c calc_state_operator.c calc_state_number.c calc_get_priority.c calc_get_number.c calc_get_operator.c calc_evaluate.c calc_convert_to_postfix.c calc_is_unary.c calc_is_binary.c calc_is_operator.c calc_operate.c calc_operate_mlt.c calc_operate_div.c calc_operate_mod.c calc_operate_sub.c calc_operate_add.c calc_operate_grt.c calc_operate_les.c calc_operate_goe.c calc_operate_loe.c calc_operate_eql.c calc_operate_neq.c calc_operate_and.c calc_operate_or.c)

target_link_libraries(calc cc)