/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/26 15:56:55 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * The `load_walk` function loads a series of images representing frames of a
 * walking animation. It loads these images into an array of textures stored in
 * the `data` structure, each corresponding to a different frame of the
 * walking animation.
 */

void	load_walk(t_data *data)
{
	data->player.walk.texture[0] = load_image("textures/walk/f_00.xpm", data);
	data->player.walk.texture[1] = load_image("textures/walk/f_01.xpm", data);
	data->player.walk.texture[2] = load_image("textures/walk/f_02.xpm", data);
	data->player.walk.texture[3] = load_image("textures/walk/f_03.xpm", data);
	data->player.walk.texture[4] = load_image("textures/walk/f_04.xpm", data);
	data->player.walk.texture[5] = load_image("textures/walk/f_05.xpm", data);
	data->player.walk.texture[6] = load_image("textures/walk/f_06.xpm", data);
	data->player.walk.texture[7] = load_image("textures/walk/f_07.xpm", data);
	data->player.walk.texture[8] = load_image("textures/walk/f_08.xpm", data);
	data->player.walk.texture[9] = load_image("textures/walk/f_09.xpm", data);
	data->player.walk.texture[10] = load_image("textures/walk/f_10.xpm", data);
	data->player.walk.texture[11] = load_image("textures/walk/f_11.xpm", data);
	data->player.walk.texture[12] = load_image("textures/walk/f_12.xpm", data);
	data->player.walk.texture[13] = load_image("textures/walk/f_13.xpm", data);
	data->player.walk.texture[14] = load_image("textures/walk/f_14.xpm", data);
	data->player.walk.texture[15] = load_image("textures/walk/f_15.xpm", data);
	data->player.walk.texture[16] = load_image("textures/walk/f_16.xpm", data);
	data->player.walk.texture[17] = load_image("textures/walk/f_17.xpm", data);
	data->player.walk.texture[18] = load_image("textures/walk/f_18.xpm", data);
	data->player.walk.texture[19] = load_image("textures/walk/f_19.xpm", data);
	data->player.walk.texture[20] = load_image("textures/walk/f_20.xpm", data);
}

/*
 * The `load_images` function loads various textures and images required for the
 * game, such as wall textures, door texture, floor texture, and ceiling texture.
 * It also creates images for floor and ceiling textures, printing messages
 * indicating the creation of these images along with their dimensions. Finally,
 * it initializes other necessary components related to textures and images.
 */

void	load_images(t_data *data)
{
	data->map.no_texture = load_image(data->map.no_file, data);
	data->map.so_texture = load_image(data->map.so_file, data);
	data->map.we_texture = load_image(data->map.we_file, data);
	data->map.ea_texture = load_image(data->map.ea_file, data);
	data->map.d_texture = load_image("textures/door.xpm", data);
	load_walk(data);
	data->map.f_image = new_img(WIDTH, HEIGHT / 2, data);
	printf("- Image created: (floor texture) (ptr=%p) (%ix%i pixels)\n",
		data->map.f_image.ptr, data->map.f_image.w, data->map.f_image.h);
	data->map.c_image = new_img(WIDTH, HEIGHT / 2, data);
	printf("- Image created: (ceiling texture) (ptr=%p) (%ix%i pixels)\n",
		data->map.c_image.ptr, data->map.c_image.w, data->map.c_image.h);
	make_floor_and_cell(data);
}
