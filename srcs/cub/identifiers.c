/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/18 18:37:52 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	identifiers(int x, int y, t_data *data)
{
	if (data->map.matrix[y][x] == ' ')
		printf(GREENB "  " NC);
	else if (data->map.matrix[y][x] == '1')
		printf(VIOLETB "  " NC);
	else if (data->map.matrix[y][x] == '2')
		printf(GRAYB "  " NC);
	else if (data->map.matrix[y][x] == 'N')
		north(x, y, data);
	else if (data->map.matrix[y][x] == 'S')
		south(x, y, data);
	else if (data->map.matrix[y][x] == 'E')
		east(x, y, data);
	else if (data->map.matrix[y][x] == 'W')
		west(x, y, data);
	else if (data->map.matrix[y][x] == '0')
		empty_space(x, y, data);
	else if (data->map.matrix[y][x] == '\0')
		return ;
	else
	{
		printf(BLACK REDB "%c " NC, data->map.matrix[y][x]);
		data->map.error_found = 1;
	}
}
