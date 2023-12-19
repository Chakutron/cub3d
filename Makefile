# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 15:15:55 by mchiboub          #+#    #+#              #
#    Updated: 2023/12/19 17:20:13 by ocassany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

GNL = gnl

MLX = mlx
MLX_LIB = libmlx.a

SRCS =	cub3d.c						\
		check_map.c					\
		ft_itoa.c					\
		handle_events.c				\
		image_utils.c				\
		init_game.c					\
		load_image.c				\
		load_map.c					\
		render.c					\
		show_interface.c			\
		show_map.c					\
		titles.c					\
		update_player.c				\
		open_map.c					\
		ft_atoi.c					\
		ft_calloc.c					\
		ft_bzero.c					\
		ft_strcat2.c				\
		ft_strdup2.c				\
		ft_strjoin3.c				\
		color.c						\
		raycasting.c				\
		${GNL}/get_next_line.c		\
		${GNL}/get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

GREEN = \033[0;32m
NC = \033[0m

all: ${NAME}

.c.o:
		@${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -lm -Lmlx -lmlx -Imlx -lX11 -lXext

${NAME}: ${OBJS}
		@echo "Generating ${GREEN}${NAME}${NC} executable.."
		@${CC} -o ${NAME} ${OBJS} ${MLX}/${MLX_LIB} -lm -Lmlx -lmlx -Imlx -lX11 -lXext

clean:
		@echo "Deleting object files.."
		@rm -f ${OBJS}

fclean: clean
		@echo "Deleting object & executable files.."
		@rm -f ${NAME}

re: fclean all
