/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   west.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/18 18:06:37 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * The `west` function updates the player's position and angle when facing
 * westward. It validates the position and its surroundings before updating the
 * player's coordinates and angle. If the position is invalid,
 * it sets an error flag.
 */

void	west(int x, int y, t_data *data)
{
	if (data->player.nbr)
	{
		printf(BLACK REDB "%c " NC, data->map.matrix[y][x]);
		data->map.error_found = 1;
	}
	else
	{
		if (check_surround(data, x, y))
		{
			printf(BLACK REDB "%c " NC, data->map.matrix[y][x]);
			data->map.error_found = 1;
		}
		else
		{
			printf(BLUEB "  " NC);
			data->player.x = x;
			data->player.y = y;
			data->player.xx = x + 0.5;
			data->player.yy = y + 0.5;
			data->player.angle = 180;
			data->player.nbr = 1;
			data->map.matrix[y][x] = '0';
		}
	}
}
