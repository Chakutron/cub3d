/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/14 19:52:45 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		data->endgame = 1;
	if (keysym == 119 || keysym == 65362)
		data->key.w = -1 + data->key.s;
	if (keysym == 115 || keysym == 65364)
		data->key.s = 1 + data->key.w;
	if (keysym == 97 || keysym == 65361)
		data->key.a = -1 + data->key.d;
	if (keysym == 100 || keysym == 65363)
		data->key.d = 1 + data->key.a;
	if (keysym == 32)
	{
		if (data->map.matrix[data->player.y - 1][data->player.x] == '2' && (data->player.angle > 45 && data->player.angle < 135))
			data->map.matrix[data->player.y - 1][data->player.x] = '3';
		else if (data->map.matrix[data->player.y - 1][data->player.x] == '3' && (data->player.angle > 45 && data->player.angle < 135))
			data->map.matrix[data->player.y - 1][data->player.x] = '2';
		if (data->map.matrix[data->player.y + 1][data->player.x] == '2' && (data->player.angle > 225 && data->player.angle < 315))
			data->map.matrix[data->player.y + 1][data->player.x] = '3';
		else if (data->map.matrix[data->player.y + 1][data->player.x] == '3' && (data->player.angle > 225 && data->player.angle < 315))
			data->map.matrix[data->player.y + 1][data->player.x] = '2';
		if (data->map.matrix[data->player.y][data->player.x - 1] == '2' && (data->player.angle > 135 && data->player.angle < 225))
			data->map.matrix[data->player.y][data->player.x - 1] = '3';
		else if (data->map.matrix[data->player.y][data->player.x - 1] == '3' && (data->player.angle > 135 && data->player.angle < 225))
			data->map.matrix[data->player.y][data->player.x - 1] = '2';
		if (data->map.matrix[data->player.y][data->player.x + 1] == '2' && (data->player.angle > 315 || data->player.angle < 45))
			data->map.matrix[data->player.y][data->player.x + 1] = '3';
		else if (data->map.matrix[data->player.y][data->player.x + 1] == '3' && (data->player.angle > 315 || data->player.angle < 45))
			data->map.matrix[data->player.y][data->player.x + 1] = '2';
		if (data->map.matrix[data->player.y - 2][data->player.x] == '2' && data->map.matrix[data->player.y - 1][data->player.x] == '0' && (data->player.angle > 45 && data->player.angle < 135))
			data->map.matrix[data->player.y - 2][data->player.x] = '3';
		else if (data->map.matrix[data->player.y - 2][data->player.x] == '3' && data->map.matrix[data->player.y - 1][data->player.x] == '0' && (data->player.angle > 45 && data->player.angle < 135))
			data->map.matrix[data->player.y - 2][data->player.x] = '2';
		if (data->map.matrix[data->player.y + 2][data->player.x] == '2' && data->map.matrix[data->player.y + 1][data->player.x] == '0' && (data->player.angle > 225 && data->player.angle < 315))
			data->map.matrix[data->player.y + 2][data->player.x] = '3';
		else if (data->map.matrix[data->player.y + 2][data->player.x] == '3' && data->map.matrix[data->player.y + 1][data->player.x] == '0' && (data->player.angle > 225 && data->player.angle < 315))
			data->map.matrix[data->player.y + 2][data->player.x] = '2';
		if (data->map.matrix[data->player.y][data->player.x - 2] == '2' && data->map.matrix[data->player.y][data->player.x - 1] == '0' && (data->player.angle > 135 && data->player.angle < 225))
			data->map.matrix[data->player.y][data->player.x - 2] = '3';
		else if (data->map.matrix[data->player.y][data->player.x - 2] == '3' && data->map.matrix[data->player.y][data->player.x - 1] == '0' && (data->player.angle > 135 && data->player.angle < 225))
			data->map.matrix[data->player.y][data->player.x - 2] = '2';
		if (data->map.matrix[data->player.y][data->player.x + 2] == '2' && data->map.matrix[data->player.y][data->player.x + 1] == '0' && (data->player.angle > 315 || data->player.angle < 45))
			data->map.matrix[data->player.y][data->player.x + 2] = '3';
		else if (data->map.matrix[data->player.y][data->player.x + 2] == '3' && data->map.matrix[data->player.y][data->player.x + 1] == '0' && (data->player.angle > 315 || data->player.angle < 45))
			data->map.matrix[data->player.y][data->player.x + 2] = '2';
		update(data);
	}
	return (0);
}
