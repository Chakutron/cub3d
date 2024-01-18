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

void	load_images(t_data *data)
{
	data->map.NO_texture = load_image(data->map.NO_file, data);
	data->map.SO_texture = load_image(data->map.SO_file, data);
	data->map.WE_texture = load_image(data->map.WE_file, data);
	data->map.EA_texture = load_image(data->map.EA_file, data);
	data->map.D_texture = load_image("textures/door.xpm", data);
	data->map.F_image = new_img(WIDTH, HEIGHT / 2, data);
	printf("- Image created: (floor texture) (ptr=%p) (%ix%i pixels)\n",
		data->map.F_image.ptr, data->map.F_image.w, data->map.F_image.h);
	data->map.C_image = new_img(WIDTH, HEIGHT / 2, data);
	printf("- Image created: (ceilling texture) (ptr=%p) (%ix%i pixels)\n",
		data->map.C_image.ptr, data->map.C_image.w, data->map.C_image.h);
	make_floor_and_cell(data);
}
