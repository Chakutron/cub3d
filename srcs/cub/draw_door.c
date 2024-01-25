/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/23 18:18:16 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * The `draw_door2` function renders a single pixel of a door texture onto the
 * canvas if the corresponding pixel on the canvas is either the ceiling color
 * or the floor color. It calculates the texture's vertical position based on
 * the pixel's position within the door's area and assigns the corresponding
 * color from the door texture to the canvas.
 */

void	draw_door2(t_data *data, int index, int y, int x)
{
	if (get_pixel_img(&data->canvas, x, y) == (unsigned int)data->map.cell.color
		|| get_pixel_img(&data->canvas, x, y)
		== (unsigned int)data->map.floor.color)
		put_pixel_img(&(data->canvas), x, y,
			get_pixel_img(&data->map.D_texture, data->r3d[index].texture_init,
				(y - data->r3d[index].y_init) * (49 / (data->r3d[index].y_end
						- data->r3d[index].y_init))));
}

/*
 * The `draw_door` function renders a door on the screen using raycasting. It
 * iterates over the area covered by the door in the player's field of view and
 * calls `draw_door2` to render the door at each pixel. The rendering is
 * confined to the screen boundaries (WIDTH and HEIGHT).
 */

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
				draw_door2(data, index, y, x);
			x++;
		}
		y++;
	}
}
