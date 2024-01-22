/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   north.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/18 18:04:14 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	north(int x, int y, t_data *data)
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
			data->player.angle = 90;
			data->player.nbr = 1;
			data->map.matrix[y][x] = '0';
		}
	}
}
