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

void	draw_minimap2(t_data *data, int color)
{
	data->ds.y_init = data->tmp.yy * MINIMAP / data->ratio / 9
		- data->dm.y_offset;
	data->ds.x_init = data->tmp.xx * MINIMAP / data->ratio / 9
		- data->dm.x_offset;
	data->ds.extra = MINIMAP / data->ratio / 9 - 1;
	data->ds.color = color;
	draw_square(data);
}

void	draw_minimap4(t_data *data)
{
	if (data->map.matrix[data->tmp.y][data->tmp.x] == ' ')
		draw_minimap2(data, 0x0000FF00);
	else if (data->map.matrix[data->tmp.y][data->tmp.x] == '0')
		draw_minimap2(data, 0x00FFFF00);
	else if (data->map.matrix[data->tmp.y][data->tmp.x] == '1')
		draw_minimap2(data, 0x00BB00FF);
}

void	draw_minimap3(t_data *data)
{
	data->ds.y_init = 0;
	data->ds.x_init = 0;
	data->ds.extra = MINIMAP / data->ratio;
	data->ds.color = 0x00000000;
	draw_square(data);
	data->dm.y_offset = MINIMAP / data->ratio / 9
		* ((data->player.yy - (double)data->player.y) + 0.5);
	data->dm.x_offset = MINIMAP / data->ratio / 9
		* ((data->player.xx - (double)data->player.x) + 0.5);
}

void	draw_minimap(t_data *data)
{
	draw_minimap3(data);
	data->tmp.y = data->player.y - 5;
	data->tmp.yy = 0;
	while (data->tmp.y <= data->player.y + 5)
	{
		data->tmp.x = data->player.x - 5;
		data->tmp.xx = 0;
		while (data->tmp.x <= data->player.x + 5)
		{
			if (data->tmp.y >= 0 && data->tmp.y < data->map.h
				&& data->tmp.x >= 0 && data->tmp.x < data->map.w)
				draw_minimap4(data);
			else
				draw_minimap2(data, 0xFF00FF00);
			data->tmp.x++;
			data->tmp.xx++;
		}
		data->tmp.y++;
		data->tmp.yy++;
	}
}
