/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_variables.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/14 19:27:44 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_variables(t_data *data)
{
	int	i;

	printf("NO file = %s\n", data->map.NO_file);
	printf("SO file = %s\n", data->map.SO_file);
	printf("WE file = %s\n", data->map.WE_file);
	printf("EA file = %s\n", data->map.EA_file);
	printf("Floor color = 0x%08X (%i, %i, %i)\n", data->map.floor.color,
		data->map.floor.r, data->map.floor.g, data->map.floor.b);
	printf("Cell color = 0x%08X (%i, %i, %i)\n", data->map.cell.color,
		data->map.cell.r, data->map.cell.g, data->map.cell.b);
	printf("Map dimension = (%i x %i)\n\n", data->map.h, data->map.w);
	i = 0;
	while (i < data->map.h)
	{
		printf("%s\n", data->map.matrix[i]);
		i++;
	}
}