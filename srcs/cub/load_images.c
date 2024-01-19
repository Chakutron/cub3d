/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/14 20:00:16 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_rick(t_data *data)
{
	data->rick.texture[0] = load_image("textures/special/rick_00.xpm", data);
	data->rick.texture[1] = load_image("textures/special/rick_01.xpm", data);
	data->rick.texture[2] = load_image("textures/special/rick_02.xpm", data);
	data->rick.texture[3] = load_image("textures/special/rick_03.xpm", data);
	data->rick.texture[4] = load_image("textures/special/rick_04.xpm", data);
	data->rick.texture[5] = load_image("textures/special/rick_05.xpm", data);
	data->rick.texture[6] = load_image("textures/special/rick_06.xpm", data);
	data->rick.texture[7] = load_image("textures/special/rick_07.xpm", data);
	data->rick.texture[8] = load_image("textures/special/rick_08.xpm", data);
	data->rick.texture[9] = load_image("textures/special/rick_09.xpm", data);
	data->rick.texture[10] = load_image("textures/special/rick_10.xpm", data);
	data->rick.texture[11] = load_image("textures/special/rick_11.xpm", data);
	data->rick.texture[12] = load_image("textures/special/rick_12.xpm", data);
	data->rick.texture[13] = load_image("textures/special/rick_13.xpm", data);
	data->rick.texture[14] = load_image("textures/special/rick_14.xpm", data);
	data->rick.texture[15] = load_image("textures/special/rick_15.xpm", data);
	data->rick.texture[16] = load_image("textures/special/rick_16.xpm", data);
	data->rick.texture[17] = load_image("textures/special/rick_17.xpm", data);
	data->rick.texture[18] = load_image("textures/special/rick_18.xpm", data);
	data->rick.texture[19] = load_image("textures/special/rick_19.xpm", data);
	data->rick.texture[20] = load_image("textures/special/rick_20.xpm", data);
	data->rick.texture[21] = load_image("textures/special/rick_21.xpm", data);
	data->rick.texture[22] = load_image("textures/special/rick_22.xpm", data);
	data->rick.texture[23] = load_image("textures/special/rick_23.xpm", data);
	data->rick.texture[24] = load_image("textures/special/rick_24.xpm", data);
	data->rick.texture[25] = load_image("textures/special/rick_25.xpm", data);
	data->rick.texture[26] = load_image("textures/special/rick_26.xpm", data);
}

void	load_walk(t_data *data)
{
	data->player.walk.texture[0] = load_image("textures/walk/walk_00.xpm", data);
	data->player.walk.texture[1] = load_image("textures/walk/walk_01.xpm", data);
	data->player.walk.texture[2] = load_image("textures/walk/walk_02.xpm", data);
	data->player.walk.texture[3] = load_image("textures/walk/walk_03.xpm", data);
	data->player.walk.texture[4] = load_image("textures/walk/walk_04.xpm", data);
	data->player.walk.texture[5] = load_image("textures/walk/walk_05.xpm", data);
	data->player.walk.texture[6] = load_image("textures/walk/walk_06.xpm", data);
	data->player.walk.texture[7] = load_image("textures/walk/walk_07.xpm", data);
	data->player.walk.texture[8] = load_image("textures/walk/walk_08.xpm", data);
	data->player.walk.texture[9] = load_image("textures/walk/walk_09.xpm", data);
	data->player.walk.texture[10] = load_image("textures/walk/walk_10.xpm", data);
	data->player.walk.texture[11] = load_image("textures/walk/walk_11.xpm", data);
	data->player.walk.texture[12] = load_image("textures/walk/walk_12.xpm", data);
	data->player.walk.texture[13] = load_image("textures/walk/walk_13.xpm", data);
	data->player.walk.texture[14] = load_image("textures/walk/walk_14.xpm", data);
	data->player.walk.texture[15] = load_image("textures/walk/walk_15.xpm", data);
	data->player.walk.texture[16] = load_image("textures/walk/walk_16.xpm", data);
	data->player.walk.texture[17] = load_image("textures/walk/walk_17.xpm", data);
	data->player.walk.texture[18] = load_image("textures/walk/walk_18.xpm", data);
	data->player.walk.texture[19] = load_image("textures/walk/walk_19.xpm", data);
	data->player.walk.texture[20] = load_image("textures/walk/walk_20.xpm", data);
}

void	load_images(t_data *data)
{
	data->map.NO_texture = load_image(data->map.NO_file, data);
	data->map.SO_texture = load_image(data->map.SO_file, data);
	data->map.WE_texture = load_image(data->map.WE_file, data);
	data->map.EA_texture = load_image(data->map.EA_file, data);
	data->map.D_texture = load_image("textures/door.xpm", data);
	load_rick(data);
	load_walk(data);
	data->map.F_image = new_img(WIDTH, HEIGHT / 2, data);
	printf("- Image created: (floor texture) (ptr=%p) (%ix%i pixels)\n",
		data->map.F_image.ptr, data->map.F_image.w, data->map.F_image.h);
	data->map.C_image = new_img(WIDTH, HEIGHT / 2, data);
	printf("- Image created: (ceilling texture) (ptr=%p) (%ix%i pixels)\n",
		data->map.C_image.ptr, data->map.C_image.w, data->map.C_image.h);
	make_floor_and_cell(data);
}
