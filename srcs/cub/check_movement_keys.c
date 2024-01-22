/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_movement_keys.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/22 18:36:38 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	undo_movement(t_data *data)
{
	data->player.yy = data->player.y_old;
	data->player.xx = data->player.x_old;
}

void	check_movement_keys(t_data *data)
{
	data->player.x_old = data->player.xx;
	data->player.y_old = data->player.yy;
	if (data->key.w)
	{
		data->player.yy -= data->player.y_temp;
		data->player.xx += data->player.x_temp;
		if (data->map.matrix[(int)(data->player.yy - 1.0)][(int)(data->player.xx)] == '1' && fabs(data->player.yy - (int)data->player.yy) < 0.15)
			undo_movement(data);
		if (data->map.matrix[(int)(data->player.yy + 1.0)][(int)(data->player.xx)] == '1' && fabs(data->player.yy - (int)data->player.yy) > 0.85)
			undo_movement(data);
		if (data->map.matrix[(int)data->player.yy][(int)(data->player.xx - 1.0)] == '1' && fabs(data->player.xx - (int)data->player.xx) < 0.15)
			undo_movement(data);
		if (data->map.matrix[(int)data->player.yy][(int)(data->player.xx + 1.0)] == '1' && fabs(data->player.xx - (int)data->player.xx) > 0.85)
			undo_movement(data);
		if (data->map.matrix[(int)(data->player.yy - 1.0)][(int)(data->player.xx)] == '2' && fabs(data->player.yy - (int)data->player.yy) < 0.15)
			undo_movement(data);
		if (data->map.matrix[(int)(data->player.yy + 1.0)][(int)(data->player.xx)] == '2' && fabs(data->player.yy - (int)data->player.yy) > 0.85)
			undo_movement(data);
		if (data->map.matrix[(int)data->player.yy][(int)(data->player.xx - 1.0)] == '2' && fabs(data->player.xx - (int)data->player.xx) < 0.15)
			undo_movement(data);
		if (data->map.matrix[(int)data->player.yy][(int)(data->player.xx + 1.0)] == '2' && fabs(data->player.xx - (int)data->player.xx) > 0.85)
			undo_movement(data);
		data->player.y = data->player.yy;
		data->player.x = data->player.xx;
		update(data);
	}
	if (data->key.s)
	{
		data->player.yy += data->player.y_temp;
		data->player.xx -= data->player.x_temp;
		if (data->map.matrix[(int)(data->player.yy - 1.0)][(int)(data->player.xx)] == '1' && fabs(data->player.yy - (int)data->player.yy) < 0.15)
			undo_movement(data);
		if (data->map.matrix[(int)(data->player.yy + 1.0)][(int)(data->player.xx)] == '1' && fabs(data->player.yy - (int)data->player.yy) > 0.85)
			undo_movement(data);
		if (data->map.matrix[(int)data->player.yy][(int)(data->player.xx - 1.0)] == '1' && fabs(data->player.xx - (int)data->player.xx) < 0.15)
			undo_movement(data);
		if (data->map.matrix[(int)data->player.yy][(int)(data->player.xx + 1.0)] == '1' && fabs(data->player.xx - (int)data->player.xx) > 0.85)
			undo_movement(data);
		if (data->map.matrix[(int)(data->player.yy - 1.0)][(int)(data->player.xx)] == '2' && fabs(data->player.yy - (int)data->player.yy) < 0.15)
			undo_movement(data);
		if (data->map.matrix[(int)(data->player.yy + 1.0)][(int)(data->player.xx)] == '2' && fabs(data->player.yy - (int)data->player.yy) > 0.85)
			undo_movement(data);
		if (data->map.matrix[(int)data->player.yy][(int)(data->player.xx - 1.0)] == '2' && fabs(data->player.xx - (int)data->player.xx) < 0.15)
			undo_movement(data);
		if (data->map.matrix[(int)data->player.yy][(int)(data->player.xx + 1.0)] == '2' && fabs(data->player.xx - (int)data->player.xx) > 0.85)
			undo_movement(data);
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
