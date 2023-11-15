# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misargsy <misargsy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/20 17:19:47 by misargsy          #+#    #+#              #
#    Updated: 2023/10/31 20:11:43 by misargsy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror #-fsanitize=address

SRCS =	push_swap.c \
		ps_optimization.c \
		ps_sort_small.c \
		ps_parse_util.c \
		ps_sort_util.c \
		ps_queueops.c \
		ps_stackops.c \
		ps_pushswap.c \
		ps_rotate.c \
		ps_coco.c \
		ps_sort.c \
		ps_mix.c

LIBFT = libft.a

OBJS = $(SRCS:.c=.o)

CHECK		= \033[32m[✔]\033[0m
BLUE		= \033[1;34m
RESET		= \033[0m

ifeq ($(filter bonus, $(MAKECMDGOALS)), bonus)
	SRCS += main_bonus.c
	NAME = checker
else
	SRCS += main_mandatory.c
	NAME = push_swap
endif

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@echo "$(BLUE)Compiling $(NAME)... $(RESET)"
	@cc $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(CHECK) $(RESET)"
	@clear
	@make banner

$(LIBFT):
	@echo "$(BLUE)Compiling libft... $(RESET)"
	@make -C libft
	@mv libft/libft.a .
	@echo "$(CHECK) $(RESET)"

%.o: %.c
	@cc $(FLAGS) -c $< -o $@

clean:
	@echo "$(BLUE)Removing object and library files... $(RESET)"
	@rm -f $(OBJS) main_bonus.o main_mandatory.o libft.a
	@make clean -C libft
	@echo "$(CHECK) $(RESET)"

fclean: clean
	@echo "$(BLUE)Removing executables... $(RESET)"
	@rm -f checker push_swap
	@make fclean -C libft
	@echo "$(CHECK) $(RESET)"

re:	fclean	all

banner:
	@cc $(FLAGS) ps_banner.c -o banner
	@./banner
	@rm banner

.PHONY: all bonus clean fclean re banner
