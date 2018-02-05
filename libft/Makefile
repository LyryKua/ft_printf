# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khrechen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 14:55:42 by khrechen          #+#    #+#              #
#    Updated: 2018/01/30 15:34:15 by khrechen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SWITCH :=		\033[

NORMAL :=		$(SWITCH)0m
BOLD :=			$(SWITCH)1m
RED :=			$(SWITCH)31m
GREEN :=		$(SWITCH)32m
YELLOW :=		$(SWITCH)33m
CYAN :=			$(SWITCH)36m
LIGHT_RED :=	$(SWITCH)91m
LIGHT_YELLOW :=	$(SWITCH)93m
LIGHT_GREEN :=	$(SWITCH)92m
LIGHT_CYAN :=	$(SWITCH)96m

NAME :=			libft.a

INC_DIR :=		./inc/

PART1 :=		ft_memset.c			\
				ft_bzero.c			\
				ft_memcpy.c			\
				ft_memccpy.c		\
				ft_memmove.c		\
				ft_memchr.c			\
				ft_memcmp.c			\
				ft_strlen.c			\
				ft_strdup.c			\
				ft_strcpy.c			\
				ft_strncpy.c		\
				ft_strcat.c			\
				ft_strncat.c		\
				ft_strlcat.c		\
				ft_strchr.c			\
				ft_strrchr.c		\
				ft_strstr.c			\
				ft_strnstr.c		\
				ft_strcmp.c			\
				ft_strncmp.c		\
				ft_atoi.c			\
				ft_isalpha.c		\
				ft_isdigit.c		\
				ft_isalnum.c		\
				ft_isascii.c		\
				ft_isprint.c		\
				ft_toupper.c		\
				ft_tolower.c

PART2 :=		ft_memalloc.c		\
				ft_memdel.c			\
				ft_strnew.c			\
				ft_strdel.c			\
				ft_strclr.c			\
				ft_striter.c		\
				ft_striteri.c		\
				ft_strmap.c			\
				ft_strmapi.c		\
				ft_strequ.c			\
				ft_strnequ.c		\
				ft_strsub.c			\
				ft_strjoin.c		\
				ft_strtrim.c		\
				ft_strsplit.c		\
				ft_itoa.c			\
				ft_putchar.c		\
				ft_putstr.c			\
				ft_putendl.c		\
				ft_putnbr.c			\
				ft_putchar_fd.c		\
				ft_putstr_fd.c		\
				ft_putendl_fd.c		\
				ft_putnbr_fd.c

PART3 :=		ft_lstnew.c			\
				ft_lstdelone.c		\
				ft_lstdel.c			\
				ft_lstadd.c			\
				ft_lstiter.c		\
				ft_lstmap.c

MY_PART :=		ft_isspace.c		\
				ft_abs.c			\
				ft_labs.c			\
				ft_llabs.c			\
				ft_itoa_base.c		\
				ft_ltoa_base.c		\
				ft_lltoa_base.c		\
				ft_uitoa_base.c		\
				ft_ultoa_base.c		\
				ft_ulltoa_base.c	\
				ft_putunichar.c

SRCS :=			$(PART1) $(PART2) $(PART3) $(MY_PART)

OBJS_DIR :=		objs/
OBJS :=			$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

CC :=			gcc
CFLAGS :=		-Wall -Werror -Wextra

INC :=			-I$(INC_DIR)

FLAGS :=		$(CFLAGS) $(INC)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS_DIR)%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(OBJS): | $(OBJS_DIR)

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(SRCS) $(INC_DIR)libft.h

pu:
	git add author .gitignore Makefile $(SRCS) $(INC_DIR)libft.h
