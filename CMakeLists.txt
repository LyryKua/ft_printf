cmake_minimum_required(VERSION 3.8)

project(ft_printf)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")

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
		libft/ft_putunichar.c
		main.c
		) # sources

add_executable(ft_printf ${SOURCE_FILES}) # compilation
