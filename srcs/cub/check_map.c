/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/14 19:43:28 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map(t_data *data)
{
	int	x;
	int	y;
	int	error_found;

	error_found = 0;
	y = 0;
	while (y < data->map.h)
	{
		x = 0;
		while (x < data->map.w)
		{
			if (data->map.matrix[y][x] == ' ')
				printf(GREENB "  " NC);
			else if (data->map.matrix[y][x] == '1')
				printf(VIOLETB "  " NC);
			else if (data->map.matrix[y][x] == 'N')
			{
				if (data->player.nbr)
				{
					printf(BLACK REDB "%c " NC, data->map.matrix[y][x]);
					error_found = 1;
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
			else if (data->map.matrix[y][x] == 'S')
			{
				if (data->player.nbr)
				{
					printf(BLACK REDB "%c " NC, data->map.matrix[y][x]);
					error_found = 1;
				}
				else
				{
					printf(BLUEB "  " NC);
					data->player.x = x;
					data->player.y = y;
					data->player.xx = x + 0.5;
					data->player.yy = y + 0.5;
					data->player.angle = 270;
					data->player.nbr = 1;
					data->map.matrix[y][x] = '0';
				}
			}
			else if (data->map.matrix[y][x] == 'E')
			{
				if (data->player.nbr)
				{
					printf(BLACK REDB "%c " NC, data->map.matrix[y][x]);
					error_found = 1;
				}
				else
				{
					printf(BLUEB "  " NC);
					data->player.x = x;
					data->player.y = y;
					data->player.xx = x + 0.5;
					data->player.yy = y + 0.5;
					data->player.angle = 0;
					data->player.nbr = 1;
					data->map.matrix[y][x] = '0';
				}
			}
			else if (data->map.matrix[y][x] == 'W')
			{
				if (data->player.nbr)
				{
					printf(BLACK REDB "%c " NC, data->map.matrix[y][x]);
					error_found = 1;
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
			else if (data->map.matrix[y][x] == '0')
			{
				if (check_surround(data, x, y))
				{
					printf(BLACK REDB "%c " NC, data->map.matrix[y][x]);
					error_found = 1;
				}
				else
					printf(YELLOWB "  " NC);
			}
			else if (data->map.matrix[y][x] == '\0')
				break ;
			else
			{
				printf(BLACK REDB "%c " NC, data->map.matrix[y][x]);
				error_found = 1;
			}
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
	if (!data->player.nbr)
		error_found = 1;
	return (error_found);
}
