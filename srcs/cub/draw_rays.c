/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/23 18:11:27 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_rays4(t_data *data, int color)
{
	data->ds.y_init = MINIMAP / data->ratio / 2 - (data->player.y
			- (int)data->rays.dy) * (MINIMAP / data->ratio / 9)
		- (data->player.yy - data->player.y)
		* (MINIMAP / data->ratio / 9);
	data->ds.x_init = MINIMAP / data->ratio / 2 - (data->player.x
			- (int)data->rays.dx) * (MINIMAP / data->ratio / 9)
		- (data->player.xx - data->player.x)
		* (MINIMAP / data->ratio / 9);
	data->ds.extra = (MINIMAP / data->ratio / 9) - 1;
	data->ds.color = color;
	draw_square(data);
	data->tmp.y0 = MINIMAP / data->ratio / 2;
	data->tmp.x0 = MINIMAP / data->ratio / 2;
	data->tmp.y1 = (MINIMAP / 2 - data->rays.y) / data->ratio;
	data->tmp.x1 = (MINIMAP / 2 + data->rays.x) / data->ratio;
	draw_line(data);
	data->rays.y3 = data->player.y - data->rays.dy;
	data->rays.x3 = data->player.x - data->rays.dx;
	data->r3d[data->rays.index].y_init = 225 - ((MINIMAP / 9)
			* (HEIGHT - (MINIMAP / 9))
			/ (data->rays.offset * cos((fabs(-data->rays.i) * M_PI) / 180)));
	data->r3d[data->rays.index].x_init = 900 - (data->rays.index + 1)
		* (WIDTH / RAYS);
}

void	draw_rays2(t_data *data, int color)
{
	draw_rays4(data, color);
	data->r3d[data->rays.index].y_end = 225 + ((MINIMAP / 9)
			* (HEIGHT - (MINIMAP / 9))
			/ (data->rays.offset * cos((fabs(-data->rays.i) * M_PI) / 180)));
	data->r3d[data->rays.index].x_end = data->r3d[data->rays.index].x_init
		+ (WIDTH / RAYS);
	draw_rays_n(data);
	draw_rays_s(data);
	draw_rays_e(data);
	draw_rays_w(data);
}

int	draw_rays3(t_data *data)
{
	data->rays.y = data->player.y_temp * data->rays.offset * 100;
	data->rays.x = data->player.x_temp * data->rays.offset * 100;
	data->rays.dy = ((MINIMAP / 2 - data->rays.y) - 4.5
			* (MINIMAP / 9)) / (MINIMAP / 9) + data->player.yy;
	data->rays.dx = ((MINIMAP / 2 + data->rays.x) - 4.5
			* (MINIMAP / 9)) / (MINIMAP / 9) + data->player.xx;
	if (data->map.matrix[(int)data->rays.dy][(int)data->rays.dx] == '1')
	{
		draw_rays2(data, 0x00FF0000);
		draw_wall(data, data->rays.index);
		return (1);
	}
	else if (data->map.matrix[(int)data->rays.dy][(int)data->rays.dx] == '2')
	{
		draw_rays2(data, 0x00FFFFFF);
		draw_door(data, data->rays.index);
		return (1);
	}
	data->rays.offset += 0.1;
	return (0);
}

void	draw_rays(t_data *data)
{
	data->rays.index = 0;
	data->rays.i = -16;
	while (data->rays.i <= 16)
	{
		data->rays.angle = data->player.angle + data->rays.i;
		if (data->rays.angle < 0)
			data->rays.angle += 360;
		if (data->rays.angle > 360)
			data->rays.angle -= 360;
		data->player.radians = (data->rays.angle * M_PI) / 180.0;
		data->player.y_temp = 0.01 * sin(data->player.radians);
		data->player.x_temp = 0.01 * cos(data->player.radians);
		data->rays.offset = 1;
		while (1)
		{
			if (draw_rays3(data))
				break ;
		}
		data->rays.i += 0.25;
		data->rays.index++;
	}
}
