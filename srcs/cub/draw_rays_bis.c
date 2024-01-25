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

void	draw_rays_n(t_data *data)
{
	if (data->rays.y3 <= 0.0 && fabs(data->rays.y3) - (int)fabs(data->rays.y3)
		< fabs(data->rays.x3) - (int)fabs(data->rays.x3)
		&& (data->map.matrix[(int)data->rays.dy - 1][(int)data->rays.dx] == '0'
		|| data->map.matrix[(int)data->rays.dy - 1][(int)data->rays.dx] == '2'
		|| data->map.matrix[(int)data->rays.dy - 1][(int)data->rays.dx] == '3')
		&& data->player.yy < data->rays.dy)
	{
		data->r3d[data->rays.index].wall = 'N';
		data->r3d[data->rays.index].texture_init
			= (int)((1 - (data->rays.dx - (int)data->rays.dx)) * 49);
	}
}

void	draw_rays_s(t_data *data)
{
	if (data->rays.y3 >= 0.0 && fabs(data->rays.y3)
		- (int)fabs(data->rays.y3) < fabs(data->rays.x3)
		- (int)fabs(data->rays.x3)
		&& (data->map.matrix[(int)data->rays.dy + 1][(int)data->rays.dx] == '0'
		|| data->map.matrix[(int)data->rays.dy + 1][(int)data->rays.dx] == '2'
		|| data->map.matrix[(int)data->rays.dy + 1][(int)data->rays.dx] == '3')
		&& data->player.yy > data->rays.dy)
	{
		data->r3d[data->rays.index].wall = 'S';
		data->r3d[data->rays.index].texture_init
			= (int)((data->rays.dx - (int)data->rays.dx) * 49);
	}
}

void	draw_rays_e(t_data *data)
{
	if (data->rays.x3 >= 0.0 && fabs(data->rays.y3)
		- (int)fabs(data->rays.y3) > fabs(data->rays.x3)
		- (int)fabs(data->rays.x3)
		&& (data->map.matrix[(int)data->rays.dy][(int)data->rays.dx + 1] == '0'
		|| data->map.matrix[(int)data->rays.dy][(int)data->rays.dx + 1] == '2'
		|| data->map.matrix[(int)data->rays.dy][(int)data->rays.dx + 1] == '3')
		&& data->player.xx > data->rays.dx)
	{
		data->r3d[data->rays.index].wall = 'E';
		data->r3d[data->rays.index].texture_init
			= (int)((1 - (data->rays.dy - (int)data->rays.dy)) * 49);
	}
}

void	draw_rays_w(t_data *data)
{
	if (data->rays.x3 <= 0.0 && fabs(data->rays.y3)
		- (int)fabs(data->rays.y3) > fabs(data->rays.x3)
		- (int)fabs(data->rays.x3)
		&& (data->map.matrix[(int)data->rays.dy][(int)data->rays.dx - 1] == '0'
		|| data->map.matrix[(int)data->rays.dy][(int)data->rays.dx - 1] == '2'
		|| data->map.matrix[(int)data->rays.dy][(int)data->rays.dx - 1] == '3')
		&& data->player.xx < data->rays.dx)
	{
		data->r3d[data->rays.index].wall = 'W';
		data->r3d[data->rays.index].texture_init
			= (int)((data->rays.dy - (int)data->rays.dy) * 49);
	}
}
