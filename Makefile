# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 15:15:55 by mchiboub          #+#    #+#              #
#    Updated: 2024/01/22 19:10:16 by ocassany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I srcs

SRC = srcs/cub
UTIL = srcs/utils
GNL = srcs/gnl

MLX = srcs/mlx
MLX_LIB = libmlx.a

SRCS =	${SRC}/add_spaces2map.c		\
		${SRC}/add_spaces2map_2.c		\
		${SRC}/calculate_vector_player.c		\
		${SRC}/check_extension.c		\
		${SRC}/check_map.c		\
		${SRC}/check_movement_keys.c		\
		${SRC}/check_nearly_elems.c		\
		${SRC}/check_surround.c		\
		${SRC}/check_variables.c		\
		${SRC}/clean_return_line.c		\
		${SRC}/close_game.c		\
		${SRC}/create_trgb.c		\
		${SRC}/cub3d.c		\
		${SRC}/draw_background.c		\
		${SRC}/draw_door.c		\
		${SRC}/draw_line.c		\
		${SRC}/draw_minimap.c		\
		${SRC}/draw_player.c		\
		${SRC}/draw_rays.c		\
		${SRC}/draw_square.c		\
		${SRC}/draw_wall.c		\
		${SRC}/east.c		\
		${SRC}/east_wall.c		\
		${SRC}/empty_space.c		\
		${SRC}/finish_gnl.c		\
		${SRC}/free_variables.c		\
		${SRC}/free_elements_store_map.c		\
		${SRC}/get_pixel_img.c		\
		${SRC}/handle_keypress.c		\
		${SRC}/handle_keyrelease.c		\
		${SRC}/handle_mouse_move.c		\
		${SRC}/identifiers.c		\
		${SRC}/init_variables.c		\
		${SRC}/load_image.c		\
		${SRC}/load_images.c		\
		${SRC}/load_map.c		\
		${SRC}/make_floor_and_cell.c		\
		${SRC}/new_file_img.c		\
		${SRC}/new_img.c		\
		${SRC}/north.c		\
		${SRC}/north_wall.c		\
		${SRC}/open_map.c		\
		${SRC}/print_error.c		\
		${SRC}/print_variables.c		\
		${SRC}/put_img_to_img.c		\
		${SRC}/put_pixel_img.c		\
		${SRC}/read_line_by_line.c		\
		${SRC}/read_variables.c		\
		${SRC}/render.c		\
		${SRC}/south.c		\
		${SRC}/south_wall.c		\
		${SRC}/start_game.c		\
		${SRC}/undo_movement.c		\
		${SRC}/unload_images.c		\
		${SRC}/update_player.c		\
		${SRC}/update.c		\
		${SRC}/west.c		\
		${SRC}/west_wall.c		\
		${SRC}/write_error.c		\
		${SRC}/x_press.c		\
		${UTIL}/check_size.c		\
		${UTIL}/ft_atoi.c		\
		${UTIL}/ft_bzero.c		\
		${UTIL}/*ft_calloc.c		\
		${UTIL}/*ft_itoa.c		\
		${UTIL}/*ft_strcat2.c		\
		${UTIL}/*ft_strdup2.c		\
		${UTIL}/*ft_strjoin3.c		\
		${UTIL}/worker.c		\
		${GNL}/get_next_line.c		\
		${GNL}/get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

GREEN = \033[0;32m
NC = \033[0m

all: ${NAME}

.c.o:
		@${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I srcs/mlx -L srcs/mlx -lmlx -lX11 -lm -lXext

${NAME}: ${OBJS}
		@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${MLX}/${MLX_LIB} -I srcs/mlx -L srcs/mlx -lmlx -lX11 -lm -lXext
		$(call put_loading)
		@echo
		@echo "Generated ${GREEN}${NAME}${NC} executable.."
		@echo

clean:
		@echo "Deleting object files.."
		@rm -f ${OBJS}

fclean: clean
		@echo "Deleting object & executable files.."
		@rm -f ${NAME}

re: fclean all

define put_loading
@progress=0;\
prog_bar="🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩";\
unprog_bar="🟥🟥🟥🟥🟥🟥🟥🟥🟥🟥";\
while [ $$progress -le 36 ]; do\
    printf "[%.*s%.*s]" $$progress $$prog_bar $$(( 36 - progress )) $$unprog_bar;\
    sleep 0.1;\
    echo -n "\e[20D";\
    progress=$$(( progress + 4 ));\
done;\
echo
endef
