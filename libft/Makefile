# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khrechen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 14:55:42 by khrechen          #+#    #+#              #
#    Updated: 2018/01/05 17:05:43 by khrechen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SWITCH :=		\033[

NORMAL :=		$(SWITCH)0m
BOLD :=			$(SWITCH)1m
LIGHT_RED :=	$(SWITCH)91m
LIGHT_YELLOW :=	$(SWITCH)93m
GREEN :=		$(SWITCH)32m
LIGHT_GREEN :=	$(SWITCH)92m
CYAN :=			$(SWITCH)36m
LIGHT_CYAN :=	$(SWITCH)96m

NAME =			libft.a

INC_DIR =		./inc/

SRCS =			ft_abs.c		\
				ft_atoi.c		\
				ft_bzero.c		\
				ft_isalnum.c	\
				ft_isalpha.c	\
				ft_isascii.c	\
				ft_isdigit.c	\
				ft_isprint.c	\
				ft_isspace.c	\
				ft_itoa.c		\
				ft_itoa_base.c	\
				ft_labs.c		\
				ft_lstadd.c		\
				ft_lstdel.c		\
				ft_lstdelone.c	\
				ft_lstiter.c	\
				ft_lstmap.c		\
				ft_lstnew.c		\
				ft_ltoa_base.c	\
				ft_memalloc.c	\
				ft_memccpy.c	\
				ft_memchr.c		\
				ft_memcmp.c		\
				ft_memcpy.c		\
				ft_memdel.c		\
				ft_memmove.c	\
				ft_memset.c		\
				ft_putchar.c	\
				ft_putchar_fd.c	\
				ft_putendl.c	\
				ft_putendl_fd.c	\
				ft_putnbr.c		\
				ft_putnbr_fd.c	\
				ft_putstr.c		\
				ft_putstr_fd.c	\
				ft_strcat.c		\
				ft_strchr.c		\
				ft_strclr.c		\
				ft_strcmp.c		\
				ft_strcpy.c		\
				ft_strdel.c		\
				ft_strdup.c		\
				ft_strequ.c		\
				ft_striter.c	\
				ft_striteri.c	\
				ft_strjoin.c	\
				ft_strlcat.c	\
				ft_strlen.c		\
				ft_strmap.c		\
				ft_strmapi.c	\
				ft_strncat.c	\
				ft_strncmp.c	\
				ft_strncpy.c	\
				ft_strnequ.c	\
				ft_strnew.c		\
				ft_strnstr.c	\
				ft_strrchr.c	\
				ft_strsplit.c	\
				ft_strstr.c		\
				ft_strsub.c		\
				ft_strtrim.c	\
				ft_tolower.c	\
				ft_toupper.c	\
				ft_uitoa_base.c

OBJS_DIR =		./objs/
OBJS =			$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

CC =			gcc
FLAGS =			-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJS_DIR)%.o: %.c
	@echo "\t-> $(CYAN)Creating $@$(NORMAL)"
	@$(CC) $(FLAGS) -I$(INC_DIR) -c $< -o $@ 

$(OBJS): | $(OBJS_DIR)

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
