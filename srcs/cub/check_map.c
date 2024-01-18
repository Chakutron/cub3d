/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/18 18:08:05 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
