/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/17 17:04:18 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line(t_data *data, int y0, int x0, int y1, int x1)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	if (x0 < x1)
		sx = 1;
	else
		sx = -1;
	if (y0 < y1)
		sy = 1;
	else
		sy = -1;
	err = dx - dy;
	while (!(x0 == x1 && y0 == y1))
	{
		if (x0 >= 0 && x0 <= MINIMAP / data->ratio && y0 >= 0
			&& y0 <= MINIMAP / data->ratio)
		{
			if (data->ratio <= 2)
			{
				if ((y0 + x0) % 2 == 0)
					put_pixel_img(&(data->canvas), x0, y0, 0x000000FF);
			}
			else
				put_pixel_img(&(data->canvas), x0, y0, 0x000000FF);
		}
		else
			break ;
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}