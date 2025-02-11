# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mez-zahi <mez-zahi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/08 14:30:14 by mez-zahi          #+#    #+#              #
#    Updated: 2025/02/11 12:19:06 by mez-zahi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT_DIR = libft
OPERATION_DIR = operation
MANDATORY_DIR = mandatory
SRCS =  $(wildcard $(MANDATORY_DIR)/*.c)

# SRCS =  push_swap.c chker_erreur.c concat_arg.c\
# 	creat_pile.c afficher_pile.c\
# 	free.c\
# 	lis.c\
# 	push_swap_utils.c \
# 	ptit_piles.c\
# 	case_grand_pile.c \
# 	init_pile.c\
# 	move_pile.c \

LIBFT_SRCS = $(wildcard $(LIBFT_DIR)/*.c)
OPERATION_SRCS = $(wildcard $(OPERATION_DIR)/*.c)

ALL_SRCS = $(SRCS) $(LIBFT_SRCS) $(OPERATION_SRCS)

OBJS = $(ALL_SRCS:.c=.o)

HEADER = push_swap.h

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) 
re : fclean all