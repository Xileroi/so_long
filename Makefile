# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yalounic <yalounic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 01:01:26 by ylounici          #+#    #+#              #
#    Updated: 2024/01/22 15:36:01 by yalounic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	get_next_line.c \
			get_next_line_utils.c \
			ft_split.c \
			parsing.c \
			main.c \
			mlx_window.c \
			mlx_ini_sprites.c \
			kill_window.c \
			image.c \
			ft_itoa.c \
			deplacement.c \
			calloc.c \
			map_name.c \
			mapable.c

OBJS	= ${SRCS:.c=.o}

NAME	= 	so_long

CC		= gcc

CFLAGS = -Werror -Wall -Wextra -I./minilibx
	
LDFLAGS	= -L./minilibx -I./minilibx -lmlx -lX11 -lXext

RM		= rm -rf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C ./ft_printf
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) ./ft_printf/*.o $(LDFLAGS) -o $(NAME)
			
all: ${NAME}
	$(MAKE) -C ./ft_printf

clean:
			${RM} ${OBJS}
			$(MAKE) -C ./ft_printf clean

fclean:		clean
			${RM} ${NAME}
			$(MAKE) -C ./ft_printf fclean

re:			fclean all

.PHONY:		all clean fclean re