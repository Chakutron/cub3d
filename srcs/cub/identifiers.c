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

/*
 * The `identifiers` function identifies different elements on the map based on
 * their characters. It prints different colors for different elements: green
 * for empty space, violet for walls, gray for doors, and specific actions are
 * triggered for player orientation ('N', 'S', 'E', 'W'). If an unknown
 * character is encountered, it prints it in red and sets an error flag.
 */

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
