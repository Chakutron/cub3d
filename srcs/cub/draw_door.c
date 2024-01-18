/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/17 16:49:10 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_door(t_data *data, int index)
{
	int	y;
	int	x;

	y = data->r3d[index].y_init;
	while (y < data->r3d[index].y_end)
	{
		x = data->r3d[index].x_init;
		while (x < data->r3d[index].x_end)
		{
			if (y >= 0 && y <= HEIGHT && x >= 0 && x <= WIDTH)
			{
				if (get_pixel_img(&data->canvas, x, y) == (unsigned int)data->map.cell.color || get_pixel_img(&data->canvas, x, y) == (unsigned int)data->map.floor.color)
						put_pixel_img(&(data->canvas), x, y, get_pixel_img(&data->map.D_texture, data->r3d[index].texture_init, (y - data->r3d[index].y_init) * (49 / (data->r3d[index].y_end - data->r3d[index].y_init))));
			}
			x++;
		}
		y++;
	}
}
