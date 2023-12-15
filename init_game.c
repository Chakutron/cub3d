/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2023/05/05 10:15:11 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_variables(t_data *data)
{
	data->player.nbr = 0;
	data->map.info.n = 0;
	data->map.info.s = 0;
	data->map.info.w = 0;
	data->map.info.e = 0;
	data->map.info.f = 0;
	data->map.info.c = 0;
	data->map.complete_info = 0;
	data->map.w = 0;
	data->map.h = 0;
	data->endgame = 0;
}

void	make_floor_and_cell(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < 240)
	{
		x = 0;
		while (x < 640)
		{
			put_pixel_img(&(data->map.F_image), x, y, data->map.floor.color);
			put_pixel_img(&(data->map.C_image), x, y, data->map.cell.color);
			x++;
		}
		y++;
	}
}

void	load_images(t_data *data)
{
	printf("\n");
	/*data->map.NO_texture = load_image(data->map.NO_file, data);
	data->map.SO_texture = load_image(data->map.SO_file, data);
	data->map.WE_texture = load_image(data->map.WE_file, data);
	data->map.EA_texture = load_image(data->map.EA_file, data);*/
	data->map.F_image = new_img(640, 240, data);
	printf("- Floor image created: (ptr=%p) (%ix%i pixels)\n", data->map.F_image.ptr, data->map.F_image.w, data->map.F_image.h);
	data->map.C_image = new_img(640, 240, data);
	printf("- Cell image created: (ptr=%p) (%ix%i pixels)\n", data->map.C_image.ptr, data->map.C_image.w, data->map.C_image.h);
	make_floor_and_cell(data);
}
