/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/22 15:22:30 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * The `check_map` function iterates through each position in the map, calling 
 * the `identifiers` function for validation. It prints the map for debugging
 * and sets an error flag if the player's position is not found, returning the 
 * error status.
 */

int	check_map(t_data *data)
{
	int	x;
	int	y;

	data->map.error_found = 0;
	y = 0;
	while (y < data->map.h)
	{
		x = 0;
		while (x < data->map.w)
		{
			identifiers(x, y, data);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
	if (!data->player.nbr)
		data->map.error_found = 1;
	return (data->map.error_found);
}
