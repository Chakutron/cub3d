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

/*
 * The `draw_wall_2` function determines which side of the wall is being
 * rendered based on the wall direction stored in `data->r3d[index].wall`. It
 * then calls the corresponding wall-drawing function (`north_wall`,
 * `south_wall`, `east_wall`, or `west_wall`) to apply the appropriate texture
 * to the canvas at the given coordinates `(x, y)`.
 */

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

/*
 * The `draw_wall` function renders the wall textures onto the canvas within the
 * specified index range. It iterates over the area defined by the index's
 * starting and ending coordinates, checks if the pixel belongs to the wall or
 * floor area, and if so, applies the wall texture accordingly.
 */

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
