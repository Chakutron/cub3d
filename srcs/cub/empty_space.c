/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchiboub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:37:09 by mchiboub          #+#    #+#             */
/*   Updated: 2024/01/18 18:05:57 by ocassany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * The `empty_space` function checks if the surrounding area of a given position
 * is empty. If the area is not empty, it sets an error flag.
 * Otherwise, it prints an empty space.
 */

void	empty_space(int x, int y, t_data *data)
{
	if (check_surround(data, x, y))
	{
		printf(BLACK REDB "%c " NC, data->map.matrix[y][x]);
		data->map.error_found = 1;
	}
	else
		printf(YELLOWB "  " NC);
}
