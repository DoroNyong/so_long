# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjang <hjang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 12:00:05 by hjang             #+#    #+#              #
#    Updated: 2025/03/17 04:50:52 by hjang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = \
		so_long.c hook_event.c read_map.c map_check.c map_check_1.c \
		map_check_2.c map_check_3.c player_move.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

PRINTF_DIR = printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS) $(MLX_LIB) $(PRINTF_LIB)
	$(CC) $(CFLAGS) -o $@ $^ -L$(MLX_DIR) -lmlx -lXext -lX11 -L$(PRINTF_DIR) -lftprintf

$(MLX_LIB) :
	make -C $(MLX_DIR)

$(PRINTF_LIB) :
	make -C $(PRINTF_DIR)

all : $(NAME)

clean :
	rm -f $(OBJS)
	make -C $(MLX_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean : clean
	rm -f $(NAME)
	make -C $(PRINTF_DIR) fclean

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY : all clean fclean re