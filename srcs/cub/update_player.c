/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2023/05/02 13:17:12 by mchiboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * The `update_player` function updates the position of the player in the game
 * map by changing the corresponding character in the map matrix to '0'.
 */

void	update_player(t_data *data, int x, int y)
{
	data->map.matrix[data->player.x][data->player.y] = '0';
	data->player.x = x;
	data->player.y = y;
}
