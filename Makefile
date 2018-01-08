# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khrechen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 14:55:42 by khrechen          #+#    #+#              #
#    Updated: 2018/01/05 20:08:02 by khrechen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SWITCH :=		\033[

NORMAL :=		$(SWITCH)0m
BOLD :=			$(SWITCH)1m
LIGHT_RED :=	$(SWITCH)91m
YELLOW :=		$(SWITCH)33m
LIGHT_YELLOW :=	$(SWITCH)93m
GREEN :=		$(SWITCH)32m
LIGHT_GREEN :=	$(SWITCH)92m
CYAN :=			$(SWITCH)36m
LIGHT_CYAN :=	$(SWITCH)96m

NAME :=			libftprintf.a

INC_DIR :=		./inc/
HEADER :=		$(INC_DIR)ft_printf.h

SRCS :=			di_lower_case.c					\
				ft_printf.c						\
				get_replacing_specification.c	\
				get_specification.c				\
				parse_print.c					\
				print_data.c					\

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
	@echo "\t-> $(YELLOW)Creating $@$(NORMAL)"
	@$(CC) $(FLAGS) -c $< -o $@ 

$(OBJS): | $(OBJS_DIR)

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

$(LIBFT): lib

lib:
	@echo "$(BOLD)$(LIGHT_CYAN)Creating libft.a...$(NORMAL)"
	@make -C libft

libclean:
	@echo "$(BOLD)$(LIGHT_RED)Deleting object files in $(LIBFT_DIR)...$(NORMAL)"
	@make clean -C $(LIBFT_DIR)

libfclean:
	@echo "$(BOLD)$(LIGHT_RED)Deleting $(LIBFT_DIR)...$(NORMAL)"
	@make fclean -C $(LIBFT_DIR)

clean: libclean
	@echo "$(BOLD)$(LIGHT_RED)Deleting $(OBJS_DIR)$(NORMAL)"
	@rm -rf $(OBJS_DIR)

fclean: clean libfclean
	@echo "$(BOLD)$(LIGHT_RED)Deleting $(NAME)$(NORMAL)"
	@rm -f $(NAME)

re: fclean all

norm:
	@norminette $(SRCS) $(HEADER)

pu: fclean 
	@echo "$(BOLD)$(LIGHT_YELLOW)Cleaned for push.$(NORMAL)"

.PHONY: all lib libclean libfclean clean fclean re norm pu
