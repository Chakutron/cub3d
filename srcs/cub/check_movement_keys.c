/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_movement_keys.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/22 19:06:46 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * The `check_undo_movement` function checks for collision with walls ('1') or 
 * door objects ('2') after the player's movement and triggers an undo if
 * necessary. It checks for collisions in multiple directions and calls the 
 * `undo_movement` function to revert the player's position if a 
 * collision occurs.
 */

void	check_undo_movement(t_data *data)
{
	if (data->map.matrix[(int)(data->player.yy - 1.0)][(int)(data->player.xx)]
		== '1' && fabs(data->player.yy - (int)data->player.yy) < 0.15)
		undo_movement(data);
	if (data->map.matrix[(int)(data->player.yy + 1.0)][(int)(data->player.xx)]
		== '1' && fabs(data->player.yy - (int)data->player.yy) > 0.85)
		undo_movement(data);
	if (data->map.matrix[(int)data->player.yy][(int)(data->player.xx - 1.0)]
		== '1' && fabs(data->player.xx - (int)data->player.xx) < 0.15)
		undo_movement(data);
	if (data->map.matrix[(int)data->player.yy][(int)(data->player.xx + 1.0)]
		== '1' && fabs(data->player.xx - (int)data->player.xx) > 0.85)
		undo_movement(data);
	if (data->map.matrix[(int)(data->player.yy - 1.0)][(int)(data->player.xx)]
		== '2' && fabs(data->player.yy - (int)data->player.yy) < 0.15)
		undo_movement(data);
	if (data->map.matrix[(int)(data->player.yy + 1.0)][(int)(data->player.xx)]
		== '2' && fabs(data->player.yy - (int)data->player.yy) > 0.85)
		undo_movement(data);
	if (data->map.matrix[(int)data->player.yy][(int)(data->player.xx - 1.0)]
		== '2' && fabs(data->player.xx - (int)data->player.xx) < 0.15)
		undo_movement(data);
	if (data->map.matrix[(int)data->player.yy][(int)(data->player.xx + 1.0)]
		== '2' && fabs(data->player.xx - (int)data->player.xx) > 0.85)
		undo_movement(data);
}

/*
 * The `s_key_movement` function handles the player's backward movement when
 * the S key is pressed. It adjusts the player's position by adding the
 * calculated y-component and subtracting the calculated x-component of the
 * movement vector. It then checks for undoing movement, updates the player's
 * position, and triggers an update of the view.
 */

void	s_key_movement(t_data *data)
{
	data->player.yy += data->player.y_temp;
	data->player.xx -= data->player.x_temp;
	check_undo_movement(data);
	data->player.y = data->player.yy;
	data->player.x = data->player.xx;
	update(data);
}

/*
 * The `w_key_movement` function handles the player's forward movement when the
 * W key is pressed. It adjusts the player's position by subtracting the
 * calculated y-component and adding the calculated x-component of the movement
 * vector. It then checks for undoing movement, updates the player's position,
 * and triggers an update of the view.
 */

void	w_key_movement(t_data *data)
{
	data->player.yy -= data->player.y_temp;
	data->player.xx += data->player.x_temp;
	check_undo_movement(data);
	data->player.y = data->player.yy;
	data->player.x = data->player.xx;
	update(data);
}

/*
 * The `check_movement_keys` function updates the player's position based on
 * the pressed movement keys. It stores the previous position, then adjusts the
 * player's angle if the A or D keys are pressed, updating the view
 * accordingly. Additionally, it triggers movement functions for forward (W)
 * and backward (S) motions.
 */

void	check_movement_keys(t_data *data)
{
	data->player.x_old = data->player.xx;
	data->player.y_old = data->player.yy;
	if (data->key.w)
		w_key_movement(data);
	if (data->key.s)
		s_key_movement(data);
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
