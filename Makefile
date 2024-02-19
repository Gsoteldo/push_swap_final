# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 16:59:28 by gsoteldo          #+#    #+#              #
#    Updated: 2024/02/17 15:39:18 by gabo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

SRC =	./src/push_swap.c \
		./src/cheap.c \
		./src/check_input.c \
		./src/free_stacks.c \
		./src/max_min_values.c \
		./src/moves_a.c \
		./src/moves_b.c \
		./src/push.c \
		./src/reverse_rotate.c \
		./src/rotate.c \
		./src/sort_3_numbers.c \
		./src/sort_4_numbers.c \
		./src/stack.c \
		./src/swap.c \
		./src/utils.c \

OBJ = $(SRC:.c=.o)

SRC_BONUS = ./bonus/checker_bonus.c

OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@mv libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJ)
	$(CC) $(CFLAGS) $(NAME) -o push_swap

play: $(NAME)
#	$(CC) $(CFLAGS) $(NAME) -o push_swap
	./push_swap 1 2 3

bonus: $(OBJ_BONUS)
	@make -C libft
	@mv libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(NAME) -o checker

clean:
	rm -f $(OBJ)
	@make clean -C libft

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all play clean fclean re 
