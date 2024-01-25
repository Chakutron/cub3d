/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_vector_player.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/16 18:13:14 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * The `calculate_vector_player` function computes the player's movement vector
 * based on their current angle and speed. It converts the angle from degrees to
 * radians, then calculates the movement components along the x and y axes using
 * trigonometric functions.
 */

void	calculate_vector_player(t_data *data)
{
	data->player.radians = (data->player.angle * M_PI) / 180.0;
	data->player.y_temp = data->player.speed * sin(data->player.radians);
	data->player.x_temp = data->player.speed * cos(data->player.radians);
}
