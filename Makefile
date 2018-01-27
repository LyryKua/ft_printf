# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khrechen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 14:55:42 by khrechen          #+#    #+#              #
#    Updated: 2018/01/27 18:04:38 by khrechen         ###   ########.fr        #
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

NAME :=			libftprintf.a

INC_DIR :=		./inc/
HEADER :=		$(INC_DIR)ft_printf.h

SRCS :=			c_lower_and_upper_case.c		\
				d_upper_case.c					\
				di_lower_case.c					\
				ft_printf.c						\
				get_replacing_specification.c	\
				get_specification.c				\
				o_lower_case.c					\
				parse_print.c					\
				print_data.c					\
				o_upper_case.c					\
				u_lower_case.c					\
				x_upper_case.c					\
				x_lower_case.c					\
				u_upper_case.c					\

OBJS_DIR :=		./objs/
OBJS :=			$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

LIBFT_DIR :=	./libft/
LIBFT :=		$(LIBFT_DIR)libft.a

INC :=			-I$(LIBFT_DIR)inc/	\
				-I$(INC_DIR)

CC :=			gcc

#CFLAGS :=		-Wall -Werror -Wextra
FLAGS :=		$(INC) $(CFLAGS)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@ar rc $(NAME) $(OBJS) $(LIBFT_DIR)/objs/*.o
	@ranlib $(NAME)
	@echo "$(BOLD)$(LIGHT_GREEN)$(NAME) is done!$(NORMAL)"

$(OBJS_DIR)%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@ 
	@echo "\t-> $(YELLOW)Created $@$(NORMAL)"

$(OBJS): | $(OBJS_DIR)

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)
	@echo "$(YELLOW)Created $(OBJS_DIR)$(NORMAL)"

$(LIBFT): lib

lib:
	@make -C libft

libclean:
	@make clean -C $(LIBFT_DIR)

libfclean:
	@make fclean -C $(LIBFT_DIR)

clean: libclean
	@rm -rf $(OBJS_DIR)
	@echo "$(BOLD)$(LIGHT_RED)Deleted $(OBJS_DIR)$(NORMAL)"

fclean: clean libfclean
	@rm -f $(NAME)
	@echo "$(BOLD)$(LIGHT_RED)Deleted $(NAME)$(NORMAL)"

re: fclean all

norm:
	@make norm -C $(LIBFT_DIR)
	@norminette $(SRCS) $(HEADER)

pu:
	@make pu -C $(LIBFT_DIR)
	@rm -rf $(OBJS_DIR)
	@rm -f $(NAME)
	@echo "$(BOLD)$(LIGHT_YELLOW)You can push ft_printf files!$(NORMAL)"
	@git add Makefile $(SRCS) $(HEADER)

.PHONY: all lib libclean libfclean clean fclean re norm pu
