# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexigar <alexigar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 12:51:16 by alexigar          #+#    #+#              #
#    Updated: 2024/05/02 12:31:11 by alexigar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CCFLAGS = -Wall -Werror -Wextra

SOURCES = push.c \
		  swap.c \
		  errors.c \
		  nodes.c \
		  operations_r_rotate.c \
		  operations_rotate.c \
		  create_stack.c \
		  order.c \
		  order_rotate.c \
		  costs.c \
		  algorithm.c \
		  high_low.c \
		  push_swap.c

OBJS = $(SOURCES:.c=.o)

$(NAME) : $(OBJS)
		@$(CC) $(OBJS) utils/libft/libft.a utils/ft_printf/libftprintf.a -o $(NAME)

all : $(NAME)

%.o : %.c
		@$(CC) -c $(CCFLAGS) $< -o $@

clean :
		@rm -rf $(OBJS)

fclean : clean
		@rm -rf $(NAME)

re : fclean all
.PHONY : all clean fclean re
