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

/*
 * The `draw_line3` function updates the error term (`err`) and adjusts the
 * current coordinates (`x0` and `y0`) of the line. It determines whether to
 * move horizontally or vertically based on the error term's relationship with
 * the differences in x and y (dx and dy). This step is essential for
 * implementing Bresenham's line algorithm and ensures the line
 * is drawn accurately.
 */

void	draw_line3(t_data *data)
{
	data->tmp.e2 = 2 * data->tmp.err;
	if (data->tmp.e2 > -data->tmp.dy)
	{
		data->tmp.err -= data->tmp.dy;
		data->tmp.x0 += data->tmp.sx;
	}
	if (data->tmp.e2 < data->tmp.dx)
	{
		data->tmp.err += data->tmp.dx;
		data->tmp.y0 += data->tmp.sy;
	}
}

/*
 * The `draw_line2` function calculates the differences (dx and dy) between the
 * endpoints' x and y coordinates, respectively, and determines the direction
 * of the line (sx and sy). It also initializes the error term used in
 * Bresenham's line algorithm.
 */

void	draw_line2(t_data *data)
{
	data->tmp.dx = abs(data->tmp.x1 - data->tmp.x0);
	data->tmp.dy = abs(data->tmp.y1 - data->tmp.y0);
	if (data->tmp.x0 < data->tmp.x1)
		data->tmp.sx = 1;
	else
		data->tmp.sx = -1;
	if (data->tmp.y0 < data->tmp.y1)
		data->tmp.sy = 1;
	else
		data->tmp.sy = -1;
	data->tmp.err = data->tmp.dx - data->tmp.dy;
}

/*
 * The `draw_line` function draws a line on the canvas using Bresenham's line
 * algorithm. It iteratively plots pixels along the line between two given
 * points. The function stops when it reaches the end point or exits the canvas
 * boundaries. Additionally, it skips drawing pixels if the line is smaller
 * than a certain threshold or alternates between pixels for a
 * smoother appearance.
 */

void	draw_line(t_data *data)
{
	draw_line2(data);
	while (!(data->tmp.x0 == data->tmp.x1 && data->tmp.y0 == data->tmp.y1))
	{
		if (data->tmp.x0 >= 0 && data->tmp.x0 <= MINIMAP / data->ratio
			&& data->tmp.y0 >= 0 && data->tmp.y0 <= MINIMAP / data->ratio)
		{
			if (data->ratio <= 2)
			{
				if ((data->tmp.y0 + data->tmp.x0) % 2 == 0)
					put_pixel_img(&(data->canvas), data->tmp.x0, data->tmp.y0,
						0x000000FF);
			}
			else
				put_pixel_img(&(data->canvas), data->tmp.x0, data->tmp.y0,
					0x000000FF);
		}
		else
			break ;
		draw_line3(data);
	}
}
