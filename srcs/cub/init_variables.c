/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/18 15:32:07 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	close_doors(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map.h)
	{
		x = 0;
		while (x < data->map.w)
		{
			if (data->map.matrix[y][x] == '3')
				data->map.matrix[y][x] = '2';
			x++;
		}
		y++;
	}
	if (data->map.matrix[data->player.y][data->player.x] == '2')
		data->map.matrix[data->player.y][data->player.x] = '3';
}

void	open_doors(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map.h)
	{
		x = 0;
		while (x < data->map.w)
		{
			if (data->map.matrix[y][x] == '2')
				data->map.matrix[y][x] = '3';
			x++;
		}
		y++;
	}
}

/*
 * Toogles the flag for BONUS to 0 (Off) or 1 (On).
 */

void	toogle_bonus(t_data *data)
{
	if (data->bonus)
	{
		data->bonus = 0;
		printf("Project BONUS: ");
		printf(RED "Off\n" NC);
		open_doors(data);
	}
	else
	{
		data->bonus = 1;
		printf("Project BONUS: ");
		printf(GREEN "On\n" NC);
		close_doors(data);
	}
	update(data);
}

/*
 * The `init_variables` function initializes various variables and flags used in
 * the program. It sets the player's initial state, initializes flags for map
 * information, initializes keys' states, sets initial game state flags, defines
 * parameters for raycasting and player movement, and sets the initial
 * cursor position.
 */

void	init_variables(t_data *data)
{
	data->player.nbr = 0;
	data->map.info.n = 0;
	data->map.info.s = 0;
	data->map.info.w = 0;
	data->map.info.e = 0;
	data->map.info.f = 0;
	data->map.info.c = 0;
	data->map.complete_info = 0;
	data->map.w = 0;
	data->map.h = 0;
	data->key.w = 0;
	data->key.s = 0;
	data->key.a = 0;
	data->key.d = 0;
	data->endgame = 0;
	data->rc_dist_offset = (WIDTH / 2) / 30;
	data->player.speed = 0.05;
	data->ratio = 5;
	data->cursor_x = 0;
	data->player.walk.index = 0;
	data->player.walk_offset = 300;
	data->timer = 0.0;
	data->bonus = 0;
}
