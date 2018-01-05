# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khrechen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 14:55:42 by khrechen          #+#    #+#              #
#    Updated: 2018/01/05 16:20:09 by khrechen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SWITCH :=		\033[

NORMAL :=		$(SWITCH)0m
BOLD :=			$(SWITCH)1m
LIGHT_RED :=	$(SWITCH)91m
LIGHT_YELLOW :=	$(SWITCH)93m
LIGHT_GREEN :=	$(SWITCH)92m

NAME :=			libftprintf.a

INC_DIR :=		./inc/

SRCS :=			get_replacing_specification.c	\
				get_specification.c				\
				ft_printf.c						\
				parse_print.c

OBJS_DIR :=		./objs/
OBJS :=			$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

LIBFT_DIR :=	./libft/
LIBFT :=		$(LIBFT_DIR)libft.a
LIBFT_OBJS :=	$(shell ls -1 $(LIBFT_DIR)objs/*.o)

INC :=			-I$(LIBFT_DIR)inc/	\
				-I$(INC_DIR)

CC :=			gcc

CFLAGS :=		-Wall -Werror -Wextra
FLAGS :=		$(INC) $(CFLAGS)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	ar rc $(NAME) $(OBJS) $(LIBFT_OBJS)
	ranlib $(NAME)

$(OBJS_DIR)%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ 

$(OBJS): | $(OBJS_DIR)

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

$(LIBFT): lib

lib:
	make -C libft

libclean:
	echo "$(BOLD)$(LIGHT_RED)Deleting object files in libraries...$(NORMAL)"
	make clean -C $(LIBFT_DIR)

libfclean:
	echo "$(BOLD)$(LIGHT_RED)Deleting libraries...$(NORMAL)"
	make fclean -C $(LIBFT_DIR)

clean: libclean
	rm -rf $(OBJS_DIR)
	echo "$(BOLD)$(LIGHT_RED)Deleted $(OBJS_DIR)$(NORMAL)"

fclean: clean libfclean
	rm -f $(NAME)
	echo "$(BOLD)$(LIGHT_RED)Deleted $(NAME)"

re: fclean all

norm:
	norminette $(SRCS)

pu: fclean 
	echo "$(BOLD)$(LIGHT_YELLOW)Cleaned for push...$(NORMAL)"

.PHONY: clean fclean re libclean libfclean pu
