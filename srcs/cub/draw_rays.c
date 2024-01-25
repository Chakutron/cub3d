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

void	draw_rays(t_data *data)
{
	float	offset;
	double	y;
	double	x;
	double	dy;
	double	dx;
	float	i;
	int		index;
	float	angle;
	float	y3;
	float	x3;

	index = 0;
	i = -16;
	while (i <= 16)
	{
		angle = data->player.angle + i;
		if (angle < 0)
			angle += 360;
		if (angle > 360)
			angle -= 360;
		data->player.radians = (angle * M_PI) / 180.0;
		data->player.y_temp = 0.01 * sin(data->player.radians);
		data->player.x_temp = 0.01 * cos(data->player.radians);
		offset = 1;
		while (1)
		{
			y = data->player.y_temp * offset * 100;
			x = data->player.x_temp * offset * 100;
			dy = ((MINIMAP / 2 - y) - 4.5 * (MINIMAP / 9)) / (MINIMAP / 9)
				+ data->player.yy;
			dx = ((MINIMAP / 2 + x) - 4.5 * (MINIMAP / 9)) / (MINIMAP / 9)
				+ data->player.xx;
			if (data->map.matrix[(int)dy][(int)dx] == '1')
			{
				data->ds.y_init = MINIMAP / data->ratio / 2 - (data->player.y - (int)dy) * (MINIMAP / data->ratio / 9) - (data->player.yy - data->player.y) * (MINIMAP / data->ratio / 9);
				data->ds.x_init = MINIMAP / data->ratio / 2 - (data->player.x - (int)dx) * (MINIMAP / data->ratio / 9) - (data->player.xx - data->player.x) * (MINIMAP / data->ratio / 9);
				data->ds.extra = (MINIMAP / data->ratio / 9) - 1;
				data->ds.color = 0x00FF0000;
				draw_square(data);
				draw_line(data,
					MINIMAP / data->ratio / 2, MINIMAP / data->ratio / 2,
					(MINIMAP / 2 - y) / data->ratio,
					(MINIMAP / 2 + x) / data->ratio);
				y3 = data->player.y - dy;
				x3 = data->player.x - dx;
				data->r3d[index].y_init = 225 - ((MINIMAP / 9)
						* (HEIGHT - (MINIMAP / 9))
						/ (offset * cos((fabs(-i) * M_PI) / 180)));
				data->r3d[index].x_init = 900 - (index + 1) * (WIDTH / RAYS);
				data->r3d[index].y_end = 225 + ((MINIMAP / 9)
						* (HEIGHT - (MINIMAP / 9))
						/ (offset * cos((fabs(-i) * M_PI) / 180)));
				data->r3d[index].x_end = data->r3d[index].x_init
					+ (WIDTH / RAYS);
				if (y3 <= 0.0
					&& fabs(y3) - (int)fabs(y3) < fabs(x3) - (int)fabs(x3)
					&& (data->map.matrix[(int)dy - 1][(int)dx] == '0'
					|| data->map.matrix[(int)dy - 1][(int)dx] == '2'
					|| data->map.matrix[(int)dy - 1][(int)dx] == '3')
					&& data->player.yy < dy)
				{
					data->r3d[index].wall = 'N';
					data->r3d[index].texture_init
						= (int)((1 - (dx - (int)dx)) * 49);
				}
				else if (y3 >= 0.0
					&& fabs(y3) - (int)fabs(y3) < fabs(x3) - (int)fabs(x3)
					&& (data->map.matrix[(int)dy + 1][(int)dx] == '0'
					|| data->map.matrix[(int)dy + 1][(int)dx] == '2'
					|| data->map.matrix[(int)dy + 1][(int)dx] == '3')
					&& data->player.yy > dy)
				{
					data->r3d[index].wall = 'S';
					data->r3d[index].texture_init = (int)((dx - (int)dx) * 49);
				}
				else if (x3 >= 0.0
					&& fabs(y3) - (int)fabs(y3) > fabs(x3) - (int)fabs(x3)
					&& (data->map.matrix[(int)dy][(int)dx + 1] == '0'
					|| data->map.matrix[(int)dy][(int)dx + 1] == '2'
					|| data->map.matrix[(int)dy][(int)dx + 1] == '3')
					&& data->player.xx > dx)
				{
					data->r3d[index].wall = 'E';
					data->r3d[index].texture_init
						= (int)((1 - (dy - (int)dy)) * 49);
				}
				else if (x3 <= 0.0
					&& fabs(y3) - (int)fabs(y3) > fabs(x3) - (int)fabs(x3)
					&& (data->map.matrix[(int)dy][(int)dx - 1] == '0'
					|| data->map.matrix[(int)dy][(int)dx - 1] == '2'
					|| data->map.matrix[(int)dy][(int)dx - 1] == '3')
					&& data->player.xx < dx)
				{
					data->r3d[index].wall = 'W';
					data->r3d[index].texture_init = (int)((dy - (int)dy) * 49);
				}
				draw_wall(data, index);
				break ;
			}
			else if (data->map.matrix[(int)dy][(int)dx] == '2')
			{
				data->ds.y_init = MINIMAP / data->ratio / 2 - (data->player.y - (int)dy) * (MINIMAP / data->ratio / 9) - (data->player.yy - data->player.y) * (MINIMAP / data->ratio / 9);
				data->ds.x_init = MINIMAP / data->ratio / 2 - (data->player.x - (int)dx) * (MINIMAP / data->ratio / 9) - (data->player.xx - data->player.x) * (MINIMAP / data->ratio / 9);
				data->ds.extra = (MINIMAP / data->ratio / 9) - 1;
				data->ds.color = 0x00FFFFFF;
				draw_square(data);
				draw_line(data,
					MINIMAP / data->ratio / 2, MINIMAP / data->ratio / 2,
					(MINIMAP / 2 - y) / data->ratio,
					(MINIMAP / 2 + x) / data->ratio);
				y3 = data->player.y - dy;
				x3 = data->player.x - dx;
				data->r3d[index].y_init = 225 - ((MINIMAP / 9)
						* (HEIGHT - (MINIMAP / 9))
						/ (offset * cos((fabs(-i) * M_PI) / 180)));
				data->r3d[index].x_init = 900 - (index + 1) * (WIDTH / RAYS);
				data->r3d[index].y_end = 225 + ((MINIMAP / 9)
						* (HEIGHT - (MINIMAP / 9))
						/ (offset * cos((fabs(-i) * M_PI) / 180)));
				data->r3d[index].x_end = data->r3d[index].x_init
					+ (WIDTH / RAYS);
				if (y3 <= 0.0
					&& fabs(y3) - (int)fabs(y3) < fabs(x3) - (int)fabs(x3)
					&& data->map.matrix[(int)dy - 1][(int)dx]
					== '0' && data->player.yy < dy)
				{
					data->r3d[index].wall = 'D';
					data->r3d[index].texture_init
						= (int)((1 - (dx - (int)dx)) * 49);
				}
				else if (y3 >= 0.0
					&& fabs(y3) - (int)fabs(y3) < fabs(x3) - (int)fabs(x3)
					&& data->map.matrix[(int)dy + 1][(int)dx]
					== '0' && data->player.yy > dy)
				{
					data->r3d[index].wall = 'D';
					data->r3d[index].texture_init = (int)((dx - (int)dx) * 49);
				}
				else if (x3 >= 0.0
					&& fabs(y3) - (int)fabs(y3) > fabs(x3) - (int)fabs(x3)
					&& data->map.matrix[(int)dy][(int)dx + 1]
					== '0' && data->player.xx > dx)
				{
					data->r3d[index].wall = 'D';
					data->r3d[index].texture_init
						= (int)((1 - (dy - (int)dy)) * 49);
				}
				else if (x3 <= 0.0
					&& fabs(y3) - (int)fabs(y3) > fabs(x3) - (int)fabs(x3)
					&& data->map.matrix[(int)dy][(int)dx - 1]
					== '0' && data->player.xx < dx)
				{
					data->r3d[index].wall = 'D';
					data->r3d[index].texture_init = (int)((dy - (int)dy) * 49);
				}
				draw_door(data, index);
				break ;
			}
			offset += 0.1;
		}
		i += 0.25;
		index++;
	}
}
