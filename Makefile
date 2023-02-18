# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 04:50:06 by bbouagou          #+#    #+#              #
#    Updated: 2023/02/18 11:40:53 by bbouagou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJ = parsing_utility.o push_swap.o push_a.o push_b.o reverse_rotate_a.o reverse_rotate_b.o reverse_rotate_both.o\
rotate_a.o rotate_b.o rotate_both.o sort_2_3_4_5.o sort_rest.o sort.o sorting_utility.o swap_a.o swap_b.o swap_both.o
OBJ_BONUS = reverse_rotate_a.o reverse_rotate_b.o reverse_rotate_both.o\
rotate_a.o rotate_b.o rotate_both.o swap_a.o swap_b.o swap_both.o checker_bonus.o parsing_utility_bonus.o push_a.o push_b.o
LIBFT = libft/libft.a
DEPS = push_swap.h checker_bonus.h

%.o: %.c $(DEPS)
	$(CC) -c $< $(CFLAGS)

all: libft $(NAME)

# $(NAME):
# 	$(CC) *.c operations/*.c $(LIBFT) -o $(NAME) 

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

bonus: libft $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)

libft:
	$(MAKE) -C libft

clean:
	$(MAKE) clean -C libft
	rm -f *.o

fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all

.PHONY: clean fclean all re libft