# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbouagou <bbouagou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 04:50:06 by bbouagou          #+#    #+#              #
#    Updated: 2023/02/17 15:44:10 by bbouagou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJ = parsing_utility.o push_swap.o
LIBFT = libft/libft.a
DEPS = push_swap.h

%.o: %.c $(DEPS)
	$(CC) -c $< $(CFLAGS)

all: libft $(NAME)

$(NAME):
	$(CC) *.c operations/*.c $(LIBFT) -o $(NAME) 

# $(NAME): $(OBJ)
# 	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

libft:
	$(MAKE) -C libft

clean:
	$(MAKE) clean -C libft
	rm -f *.o

fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re libft