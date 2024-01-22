/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/22 17:55:57 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall_2(t_data *data, int index, int y, int x)
{
	if (data->r3d[index].wall == 'N')
		north_wall(data, index, y, x);
	else if (data->r3d[index].wall == 'S')
		south_wall(data, index, y, x);
	else if (data->r3d[index].wall == 'E')
		east_wall(data, index, y, x);
	else if (data->r3d[index].wall == 'W')
		west_wall(data, index, y, x);
}

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
					draw_wall_2(data, index, y, x);
			}
			x++;
		}
		y++;
	}
}
