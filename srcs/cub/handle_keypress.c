/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/22 18:33:09 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * The `west_door_management` function toggles the state of doors west of the
 * player based on their viewing angle. It switches between open and closed
 * states for the door in front of the player and the door two tiles ahead if
 * the player is facing west.
 */

void	west_door_management(t_data *data)
{
	if (data->map.matrix[data->player.y][data->player.x - 1] == '2'
		&& (data->player.angle > 135 && data->player.angle < 225))
		data->map.matrix[data->player.y][data->player.x - 1] = '3';
	else if (data->map.matrix[data->player.y][data->player.x - 1] == '3'
		&& (data->player.angle > 135 && data->player.angle < 225))
		data->map.matrix[data->player.y][data->player.x - 1] = '2';
	if (data->map.matrix[data->player.y][data->player.x - 2] == '2'
		&& data->map.matrix[data->player.y][data->player.x - 1] == '0'
		&& (data->player.angle > 135 && data->player.angle < 225))
		data->map.matrix[data->player.y][data->player.x - 2] = '3';
	else if (data->map.matrix[data->player.y][data->player.x - 2] == '3'
		&& data->map.matrix[data->player.y][data->player.x - 1] == '0'
		&& (data->player.angle > 135 && data->player.angle < 225))
		data->map.matrix[data->player.y][data->player.x - 2] = '2';
}

/*
 * The `east_door_management` function toggles the state of doors east of the
 * player based on their viewing angle. It switches between open and closed
 * states for the door in front of the player and the door two tiles ahead if
 * the player is facing east.
 */

void	east_door_management(t_data *data)
{
	if (data->map.matrix[data->player.y][data->player.x + 1] == '2'
		&& (data->player.angle > 315 || data->player.angle < 45))
		data->map.matrix[data->player.y][data->player.x + 1] = '3';
	else if (data->map.matrix[data->player.y][data->player.x + 1] == '3'
		&& (data->player.angle > 315 || data->player.angle < 45))
		data->map.matrix[data->player.y][data->player.x + 1] = '2';
	if (data->map.matrix[data->player.y][data->player.x + 2] == '2'
		&& data->map.matrix[data->player.y][data->player.x + 1] == '0'
		&& (data->player.angle > 315 || data->player.angle < 45))
		data->map.matrix[data->player.y][data->player.x + 2] = '3';
	else if (data->map.matrix[data->player.y][data->player.x + 2] == '3'
		&& data->map.matrix[data->player.y][data->player.x + 1] == '0'
		&& (data->player.angle > 315 || data->player.angle < 45))
		data->map.matrix[data->player.y][data->player.x + 2] = '2';
}

/*
 * The `south_door_management` function toggles the state of doors south of the
 * player based on their viewing angle. It switches between open and closed
 * states for the door in front of the player and the door two tiles ahead if
 * the player is facing south.
 */

void	south_door_management(t_data *data)
{
	if (data->map.matrix[data->player.y + 1][data->player.x] == '2'
		&& (data->player.angle > 225 && data->player.angle < 315))
		data->map.matrix[data->player.y + 1][data->player.x] = '3';
	else if (data->map.matrix[data->player.y + 1][data->player.x] == '3'
		&& (data->player.angle > 225 && data->player.angle < 315))
		data->map.matrix[data->player.y + 1][data->player.x] = '2';
	if (data->map.matrix[data->player.y + 2][data->player.x] == '2'
		&& data->map.matrix[data->player.y + 1][data->player.x] == '0'
		&& (data->player.angle > 225 && data->player.angle < 315))
		data->map.matrix[data->player.y + 2][data->player.x] = '3';
	else if (data->map.matrix[data->player.y + 2][data->player.x] == '3'
		&& data->map.matrix[data->player.y + 1][data->player.x] == '0'
		&& (data->player.angle > 225 && data->player.angle < 315))
		data->map.matrix[data->player.y + 2][data->player.x] = '2';
}

/*
 * The `north_door_management` function toggles the state of doors north of the
 * player based on their viewing angle. It switches between open and closed
 * states for the door in front of the player and the door two tiles ahead if
 * the player is facing north.
 */

void	north_door_management(t_data *data)
{
	if (data->map.matrix[data->player.y - 1][data->player.x] == '2'
		&& (data->player.angle > 45 && data->player.angle < 135))
		data->map.matrix[data->player.y - 1][data->player.x] = '3';
	else if (data->map.matrix[data->player.y - 1][data->player.x] == '3'
		&& (data->player.angle > 45 && data->player.angle < 135))
		data->map.matrix[data->player.y - 1][data->player.x] = '2';
	if (data->map.matrix[data->player.y - 2][data->player.x] == '2'
		&& data->map.matrix[data->player.y - 1][data->player.x] == '0'
		&& (data->player.angle > 45 && data->player.angle < 135))
		data->map.matrix[data->player.y - 2][data->player.x] = '3';
	else if (data->map.matrix[data->player.y - 2][data->player.x] == '3'
		&& data->map.matrix[data->player.y - 1][data->player.x] == '0'
		&& (data->player.angle > 45 && data->player.angle < 135))
		data->map.matrix[data->player.y - 2][data->player.x] = '2';
}

/*
 * The `handle_keypress` function manages key presses in the game. It sets flags
 * based on the pressed keys: 'W' or up arrow for moving forward, 'S' or down
 * arrow for moving backward, 'A' or left arrow for strafing left, 'D' or right
 * arrow for strafing right, and spacebar for door management. The function also
 * updates the game state accordingly.
 */

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
		north_door_management(data);
		south_door_management(data);
		east_door_management(data);
		west_door_management(data);
		update(data);
	}
	return (0);
}
