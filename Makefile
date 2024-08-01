# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/15 18:20:36 by ohladkov          #+#    #+#              #
#    Updated: 2024/08/01 12:50:56 by ohladkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

SRCS	=	main.c exit_fractal.c hook_key.c str_utils.c draw.c \
			mandelbrot_set.c julia_set.c fractal_init.c

OBJS	= $(SRCS:.c=.o)

MLX_PATH	= minilibx-linux
MLX_NAME 	= libmlx.a
MLX			= $(MLX_PATH)/$(MLX_NAME)

CC			= cc
HEAD		= $(MLX_PATH)/libmlx.h

CFLAGS	= -Wall -Wextra -Werror -O3

LFLAGS	= -lX11 -lXext -lm

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT) $(MLX)
		$(CC) $(LFLAGS) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME) 

$(MLX):
	@make -sC $(MLX_PATH)


%.o: %.c Makefile
		$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)

re:		fclean all
