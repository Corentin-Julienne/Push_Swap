# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/06 16:06:37 by cjulienn          #+#    #+#              #
#    Updated: 2022/04/12 16:33:51 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap

## debug utils to suppress before correction
SRCS= ./srcs/actions/push.c \
	  ./srcs/actions/rotate.c \
	  ./srcs/actions/swap.c \
	  ./srcs/algos/algo_big_nbrs/algo_big_nbrs_1.c \
	  ./srcs/algos/algo_big_nbrs/algo_big_nbrs_2.c \
	  ./srcs/algos/algo_case_2.c \
	  ./srcs/algos/algo_case_3.c \
	  ./srcs/algos/algo_case_4.c \
	  ./srcs/algos/algo_case_5.c \
	  ./srcs/args_processing/check_args_validity_1.c \
	  ./srcs/args_processing/check_args_validity_2.c \
	  ./srcs/args_processing/format_input.c \
	  ./srcs/utils/algo_utils.c \
	  ./srcs/utils/free.c \
	  ./srcs/utils/interval.c \
	  ./srcs/utils/manage_stacks.c \
	  ./srcs/utils/quick_sort.c \
	  ./srcs/push_swap.c \
	  ./srcs/debug/debug_utils.c
	  
OBJS = $(SRCS:.c=.o)

INCLUDE_PATH = ./includes/

LIBFT_LIB = libft.a
LIBFT_PATH = ./libft/

CC= gcc
CFLAGS= -Wall -Wextra -Werror -I$(INCLUDE_PATH)

RM= rm -f

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)
	@echo $(NAME) successfully made !!!

all: 
	$(NAME)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(RM) $(OBJS)
	
fclean:	clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
