# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khrechen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 14:55:42 by khrechen          #+#    #+#              #
#    Updated: 2018/02/01 18:02:05 by khrechen         ###   ########.fr        #
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

SRCS :=			ft_printf.c						\
				parse_print.c					\
				get_replacing_specification.c	\
				get_specification.c				\
				print_data.c					\
				with_len.c						\
												\
				c_upper_case.c					\
				c_lower_case.c					\
				s_upper_case.c					\
				s_lower_case.c					\
				p_lower_case.c					\
												\
				dec_long_long.c					\
				dec_unsigned_long_long.c		\
				bin_unsigned_long_long.c		\
				oct_unsigned_long_long.c		\
				hex_unsigned_long_long.c

OBJS_DIR :=		./objs/
OBJS :=			$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

LIBFT_DIR :=	./libft/
LIBFT :=		$(LIBFT_DIR)libft.a

INC :=			-I$(LIBFT_DIR)inc/	\
				-I$(INC_DIR)

CC :=			gcc

CFLAGS :=		-Wall -Werror -Wextra
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
.SILENT:
