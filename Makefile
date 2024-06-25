# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/15 18:20:36 by ohladkov          #+#    #+#              #
#    Updated: 2023/11/13 19:42:52 by ohladkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

SRCS	= fractol.c exit_fractal.c hook_key.c str_utils.c draw.c mandelbrot_set.c julia_set.c fractal_init.c

OBJS	= $(SRCS:.c=.o)

DEPS	= /usr/local/include/mlx.h
LIBS	= /usr/local/lib/libmlx.a

CC		= cc

CFLAGS	= -Wall -Wextra -Werror
LFLAGS	= -lX11 -lXext -lmlx -lm

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(LFLAGS) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

%.o: %.c	$(DEPS)
		$(CC) $(CFLAGS) -c -o $@ $<

clean:
		rm -f *.o

fclean:		clean
		rm -f $(NAME)

re:		fclean all
