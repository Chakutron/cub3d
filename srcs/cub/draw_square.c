/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/23 18:35:25 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * The `draw_square` function draws a square onto the canvas with the specified
 * color. It iterates over the square's area and sets pixels to the given color.
 * It also checks for boundaries to ensure it doesn't draw outside the canvas.
 * Additionally, it handles alternate coloring if the canvas resolution is low.
 */

void	draw_square(t_data *data)
{
	int	y;
	int	x;

	y = data->ds.y_init;
	while (y < data->ds.y_init + data->ds.extra)
	{
		x = data->ds.x_init;
		while (x < data->ds.x_init + data->ds.extra)
		{
			if (y >= 0 && y <= MINIMAP / data->ratio && x >= 0
				&& x <= MINIMAP / data->ratio)
			{
				if (data->ratio <= 2)
				{
					if ((y + x) % 2 == 0)
						put_pixel_img(&(data->canvas), x, y, data->ds.color);
				}
				else
					put_pixel_img(&(data->canvas), x, y, data->ds.color);
			}
			x++;
		}
		y++;
	}
}
