cmake_minimum_required(VERSION 3.8)

project(ft_printf)

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-format-invalid-specifier -Wno-format -Wno-macro-redefined -Wno-implicitly-unsigned-literal")

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

#set(LIBS_FILES
#		libft/ft_atoi.c
#		libft/ft_bzero.c
#		libft/ft_isalnum.c
#		libft/ft_isalpha.c
#		libft/ft_isascii.c
#		libft/ft_isdigit.c
#		libft/ft_isprint.c
#		libft/ft_isspace.c
#		libft/ft_itoa.c
#		libft/ft_lstadd.c
#		libft/ft_lstdel.c
#		libft/ft_lstdelone.c
#		libft/ft_lstiter.c
#		libft/ft_lstmap.c
#		libft/ft_lstnew.c
#		libft/ft_memalloc.c
#		libft/ft_memccpy.c
#		libft/ft_memchr.c
#		libft/ft_memcmp.c
#		libft/ft_memcpy.c
#		libft/ft_memdel.c
#		libft/ft_memmove.c
#		libft/ft_memset.c
#		libft/ft_putchar.c
#		libft/ft_putchar_fd.c
#		libft/ft_putendl.c
#		libft/ft_putendl_fd.c
#		libft/ft_putnbr.c
#		libft/ft_putnbr_fd.c
#		libft/ft_putstr.c
#		libft/ft_putstr_fd.c
#		libft/ft_strcat.c
#		libft/ft_strchr.c
#		libft/ft_strclr.c
#		libft/ft_strcmp.c
#		libft/ft_strcpy.c
#		libft/ft_strdel.c
#		libft/ft_strdup.c
#		libft/ft_strequ.c
#		libft/ft_striter.c
#		libft/ft_striteri.c
#		libft/ft_strjoin.c
#		libft/ft_strlcat.c
#		libft/ft_strlen.c
#		libft/ft_strmap.c
#		libft/ft_strmapi.c
#		libft/ft_strncat.c
#		libft/ft_strncmp.c
#		libft/ft_strncpy.c
#		libft/ft_strnequ.c
#		libft/ft_strnew.c
#		libft/ft_strnstr.c
#		libft/ft_strrchr.c
#		libft/ft_strsplit.c
#		libft/ft_strstr.c
#		libft/ft_strsub.c
#		libft/ft_strtrim.c
#		libft/ft_tolower.c
#		libft/ft_toupper.c
#		)

set(SOURCE_FILES
		ft_printf.c
		get_replacing_specification.c
		get_specification.c
		parse_print.c
		print_data.c
		printf_main2.c
#		main.c
		d_upper_case.c
		di_lower_case.c
		u_lower_case.c
		u_upper_case.c
		o_lower_case.c
		o_upper_case.c
		x_lower_case.c
		x_upper_case.c
		c_lower_case.c) # sources

add_executable(ft_printf ${SOURCE_FILES}) # compilation
