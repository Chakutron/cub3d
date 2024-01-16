/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/16 17:50:25 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall(t_data *data, int index)
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
				if (get_pixel_img(&data->canvas, x, y)
					== (unsigned int)data->map.cell.color
					|| get_pixel_img(&data->canvas, x, y)
					== (unsigned int)data->map.floor.color)
				{
					if (data->r3d[index].wall == 'N')
						put_pixel_img(&(data->canvas), x, y,
							get_pixel_img(&data->map.NO_texture,
								data->r3d[index].texture_init,
								(y - data->r3d[index].y_init)
								* (49 / (data->r3d[index].y_end
										- data->r3d[index].y_init))));
					else if (data->r3d[index].wall == 'S')
						put_pixel_img(&(data->canvas), x, y,
							get_pixel_img(&data->map.SO_texture,
								data->r3d[index].texture_init,
								(y - data->r3d[index].y_init)
								* (49 / (data->r3d[index].y_end
										- data->r3d[index].y_init))));
					else if (data->r3d[index].wall == 'E')
						put_pixel_img(&(data->canvas),
							x, y, get_pixel_img(&data->map.EA_texture,
								data->r3d[index].texture_init,
								(y - data->r3d[index].y_init)
								* (49 / (data->r3d[index].y_end
										- data->r3d[index].y_init))));
					else if (data->r3d[index].wall == 'W')
						put_pixel_img(&(data->canvas), x, y, get_pixel_img(&data->map.WE_texture, data->r3d[index].texture_init, (y - data->r3d[index].y_init) * (49 / (data->r3d[index].y_end - data->r3d[index].y_init))));
				}
			}
			x++;
		}
		y++;
	}
}
