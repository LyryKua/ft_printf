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
		bin_unsigned_long_long.c
		c_lower_case.c
		c_upper_case.c
		dec_long_long.c
		dec_unsigned_long_long.c
		ft_printf.c
		get_replacing_specification.c
		get_specification.c
		hex_unsigned_long_long.c
		oct_unsigned_long_long.c
		p_lower_case.c
		parse_print.c
		print_data.c
		s_lower_case.c
		s_upper_case.c
		with_len.c

		main.c
		) # sources

add_executable(ft_printf ${SOURCE_FILES}) # compilation
