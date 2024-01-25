/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/17 16:56:23 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap(t_data *data)
{
	int	x;
	int	y;
	int	xx;
	int	yy;

	data->ds.y_init = 0;
	data->ds.x_init = 0;
	data->ds.extra = MINIMAP / data->ratio;
	data->ds.color = 0x00000000;
	draw_square(data);
	data->dm.y_offset = MINIMAP / data->ratio / 9
		* ((data->player.yy - (double)data->player.y) + 0.5);
	data->dm.x_offset = MINIMAP / data->ratio / 9
		* ((data->player.xx - (double)data->player.x) + 0.5);
	y = data->player.y - 5;
	yy = 0;
	while (y <= data->player.y + 5)
	{
		x = data->player.x - 5;
		xx = 0;
		while (x <= data->player.x + 5)
		{
			if (y >= 0 && y < data->map.h && x >= 0 && x < data->map.w)
			{
				if (data->map.matrix[y][x] == ' ')
				{
					data->ds.y_init = yy * MINIMAP / data->ratio / 9 - data->dm.y_offset;
					data->ds.x_init = xx * MINIMAP / data->ratio / 9 - data->dm.x_offset;
					data->ds.extra = MINIMAP / data->ratio / 9 - 1;
					data->ds.color = 0x0000FF00;
					draw_square(data);
				}
				else if (data->map.matrix[y][x] == '0')
				{
					data->ds.y_init = yy * MINIMAP / data->ratio / 9 - data->dm.y_offset;
					data->ds.x_init = xx * MINIMAP / data->ratio / 9 - data->dm.x_offset;
					data->ds.extra = MINIMAP / data->ratio / 9 - 1;
					data->ds.color = 0x00FFFF00;
					draw_square(data);
				}
				else if (data->map.matrix[y][x] == '1')
				{
					data->ds.y_init = yy * MINIMAP / data->ratio / 9 - data->dm.y_offset;
					data->ds.x_init = xx * MINIMAP / data->ratio / 9 - data->dm.x_offset;
					data->ds.extra = MINIMAP / data->ratio / 9 - 1;
					data->ds.color = 0x00BB00FF;
					draw_square(data);
				}
			}
			else
			{
				data->ds.y_init = yy * MINIMAP / data->ratio / 9 - data->dm.y_offset;
				data->ds.x_init = xx * MINIMAP / data->ratio / 9 - data->dm.x_offset;
				data->ds.extra = MINIMAP / data->ratio / 9 - 1;
				data->ds.color = 0xFF00FF00;
				draw_square(data);
			}
			x++;
			xx++;
		}
		y++;
		yy++;
	}
}
