cmake_minimum_required(VERSION 3.8)

project(ft_printf)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-format-invalid-specifier -Wno-format -Wno-macro-redefined -Wno-implicitly-unsigned-literal")

include_directories(
		libft/inc
#		libvector/inc
#		inc
		.
) # header directories

link_directories(
		libft
) # library directories

#set(HEADERS_FILES
#		inc/color.h
#		inc/rtv1.h
#		) # headers

set(SOURCE_FILES
		main.c
#		printf_main.c
#		printf_main2.c
		ft_printf.c
		length_of_number.c
		) # sources

add_executable(ft_printf ${SOURCE_FILES}) # compilation

target_link_libraries(ft_printf -lft) # linkage