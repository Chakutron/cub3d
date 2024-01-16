/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_movement_keys.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/14 19:47:55 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_movement_keys(t_data *data)
{
	double	x_old;
	double	y_old;

	x_old = data->player.xx;
	y_old = data->player.yy;
	if (data->key.w)
	{
		data->player.yy -= data->player.y_temp;
		data->player.xx += data->player.x_temp;
		if (data->map.matrix[(int)(data->player.yy - 10 * data->player.y_temp)]
					[(int)(data->player.xx + 10 * data->player.x_temp)] == '1')
		{
			data->player.yy = y_old;
			data->player.xx = x_old;
		}
		data->player.y = data->player.yy;
		data->player.x = data->player.xx;
		update(data);
	}
	if (data->key.s)
	{
		data->player.yy += data->player.y_temp;
		data->player.xx -= data->player.x_temp;
		if (data->map.matrix[(int)(data->player.yy + 10 * data->player.y_temp)]
					[(int)(data->player.xx - 10 * data->player.x_temp)] == '1')
		{
			data->player.yy = y_old;
			data->player.xx = x_old;
		}
		data->player.y = data->player.yy;
		data->player.x = data->player.xx;
		update(data);
	}
	if (data->key.a)
	{
		data->player.angle += 1 + data->cursor_x;
		if (data->player.angle > 360)
			data->player.angle -= 360;
		update(data);
	}
	if (data->key.d)
	{
		data->player.angle -= 1 + data->cursor_x;
		if (data->player.angle < 0)
			data->player.angle += 360;
		update(data);
	}
}
