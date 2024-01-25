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
