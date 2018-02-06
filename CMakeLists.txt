cmake_minimum_required(VERSION 3.8)

project(ft_printf)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")

include_directories(
		libft/inc
		inc
) # header directories

link_directories(
		libft
) # library directories

link_libraries(
		ft
)

set(SOURCE_FILES
		ft_printf.c
		get_replacing_specification.c
		parse_print.c
		get_specification.c

		main.c
		) # sources

set(HEADERS
		inc/ft_printf.h
		)

add_executable(ft_printf ${SOURCE_FILES} ${HEADERS}) # compilation
