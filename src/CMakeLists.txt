cmake_minimum_required(VERSION 3.14)
project(src C)

set(CMAKE_C_STANDARD 99)


include_directories(../../libft/includes)
include_directories(../includes)
FILE(GLOB LIBFT_SRCS ../../libft/src/*c)
add_executable(src
        creation_token_list.c
        ft_error.c
        ft_print.c
        ft_return.c
        helps.c
        parser.c
        tree.c
        parse_json.c
        ${LIBFT_SRCS}
        ../main.c get_int.c)
