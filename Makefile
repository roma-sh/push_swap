# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rshatra <rshatra@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 17:30:11 by rshatra           #+#    #+#              #
#    Updated: 2024/06/02 05:50:37 by rshatra          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ilibft
SRC_DIR	=	./srcs/

SRC =  $(SRC_DIR)init.c $(SRC_DIR)main.c $(SRC_DIR)swap.c \
		$(SRC_DIR)rotate.c $(SRC_DIR)reverse_rotate.c $(SRC_DIR)push.c $(SRC_DIR)sorting.c $(SRC_DIR)utlis.c\
		$(SRC_DIR)errors.c $(SRC_DIR)set_stack_topush.c $(SRC_DIR)push_swap.c\

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBS = -L$(LIBFT_DIR) -lft


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
