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

	draw_square(data, 0, 0, MINIMAP / data->ratio, 0x00000000);
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
					draw_square(data,
						yy * MINIMAP / data->ratio / 9 - data->dm.y_offset,
						xx * MINIMAP / data->ratio / 9 - data->dm.x_offset,
						MINIMAP / data->ratio / 9 - 1, 0x0000FF00);
				else if (data->map.matrix[y][x] == '0')
					draw_square(data,
						yy * MINIMAP / data->ratio / 9 - data->dm.y_offset,
						xx * MINIMAP / data->ratio / 9 - data->dm.x_offset,
						MINIMAP / data->ratio / 9 - 1, 0x00FFFF00);
				else if (data->map.matrix[y][x] == '1')
					draw_square(data,
						yy * MINIMAP / data->ratio / 9 - data->dm.y_offset,
						xx * MINIMAP / data->ratio / 9 - data->dm.x_offset,
						MINIMAP / data->ratio / 9 - 1, 0x00BB00FF);
			}
			else
				draw_square(data,
					yy * MINIMAP / data->ratio / 9 - data->dm.y_offset,
					xx * MINIMAP / data->ratio / 9 - data->dm.x_offset,
					MINIMAP / data->ratio / 9 - 1, 0xFF00FF00);
			x++;
			xx++;
		}
		y++;
		yy++;
	}
}
